use std::{
	ffi::c_void,
	marker::PhantomData,
	mem,
};

pub use ptr_extern::PtrExtern;

use crate::{
	Result,
	traits::{Boxed, OpenCVType, OpenCVTypeExternContainer},
};

#[cfg(not(feature = "opencv-32"))]
mod ptr_f32;
mod ptr_extern;

/// [docs.opencv.org 3.x](https://docs.opencv.org/3.4/d0/de7/structcv_1_1Ptr.html)
/// [docs.opencv.org 4.x](https://en.cppreference.com/w/cpp/memory/shared_ptr)
pub struct Ptr<T: ?Sized> where Self: PtrExtern {
	ptr: *mut c_void,
	_d: PhantomData<T>,
}

impl<T: ?Sized> Ptr<T> where Self: PtrExtern {
	/// Get raw pointer to the inner object
	pub fn inner_as_raw(&self) -> *const c_void {
		unsafe { self.extern_inner_as_ptr() }
	}

	/// Get mutable raw pointer to the inner object
	pub fn inner_as_raw_mut(&mut self) -> *mut c_void {
		unsafe { self.extern_inner_as_ptr_mut() }
	}
}

impl<T: ?Sized> Boxed for Ptr<T> where Self: PtrExtern {
	#[inline]
	unsafe fn from_raw(ptr: *mut c_void) -> Self {
		Self { ptr, _d: PhantomData }
	}

	#[inline]
	fn into_raw(self) -> *mut c_void {
		let out = self.ptr;
		mem::forget(self);
		out
	}

	#[inline]
	fn as_raw(&self) -> *const c_void {
		self.ptr
	}

	#[inline]
	fn as_raw_mut(&mut self) -> *mut c_void {
		self.ptr
	}
}

impl<T: ?Sized> OpenCVType<'_> for Ptr<T> where Self: PtrExtern {
	type Owned = Self;
	type Arg = Self;
	type ExternReceive = *mut c_void;
	type ExternContainer = Self;

	#[inline]
	fn opencv_into_extern_container(self) -> Result<Self::ExternContainer> {
		Ok(self)
	}

	#[inline]
	fn opencv_into_extern_container_nofail(self) -> Self::ExternContainer {
		self
	}

	#[inline]
	unsafe fn opencv_from_extern(s: Self::ExternReceive) -> Self::Owned {
		Self::from_raw(s)
	}
}

impl<T: ?Sized> OpenCVTypeExternContainer for Ptr<T> where Self: PtrExtern {
	type ExternSend = *const c_void;
	type ExternSendMut = *mut c_void;

	#[inline]
	fn opencv_to_extern(&self) -> Self::ExternSend {
		self.as_raw()
	}

	#[inline]
	fn opencv_to_extern_mut(&mut self) -> Self::ExternSendMut {
		self.as_raw_mut()
	}
}

impl<T: ?Sized> Drop for Ptr<T> where Self: PtrExtern {
	fn drop(&mut self) {
		unsafe { self.extern_delete() }
	}
}
