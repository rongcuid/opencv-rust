#include "common.hpp"
#include <opencv2/plot.hpp>
#include "plot_types.hpp"

extern "C" {
	Result<cv::Ptr<cv::plot::Plot2d>*> cv_plot_createPlot2d_const__InputArrayX(const cv::_InputArray* data) {
		try {
			cv::Ptr<cv::plot::Plot2d> ret = cv::plot::createPlot2d(*data);
			return Ok(new cv::Ptr<cv::plot::Plot2d>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::plot::Plot2d>*>))
	}
	
	Result<cv::Ptr<cv::plot::Plot2d>*> cv_plot_createPlot2d_const__InputArrayX_const__InputArrayX(const cv::_InputArray* dataX, const cv::_InputArray* dataY) {
		try {
			cv::Ptr<cv::plot::Plot2d> ret = cv::plot::createPlot2d(*dataX, *dataY);
			return Ok(new cv::Ptr<cv::plot::Plot2d>(ret));
		} OCVRS_CATCH(OCVRS_TYPE(Result<cv::Ptr<cv::plot::Plot2d>*>))
	}
	
	Result_void cv_plot_Plot2d_setMinX_double(cv::plot::Plot2d* instance, double _plotMinX) {
		try {
			instance->setMinX(_plotMinX);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setMinY_double(cv::plot::Plot2d* instance, double _plotMinY) {
		try {
			instance->setMinY(_plotMinY);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setMaxX_double(cv::plot::Plot2d* instance, double _plotMaxX) {
		try {
			instance->setMaxX(_plotMaxX);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setMaxY_double(cv::plot::Plot2d* instance, double _plotMaxY) {
		try {
			instance->setMaxY(_plotMaxY);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setPlotLineWidth_int(cv::plot::Plot2d* instance, int _plotLineWidth) {
		try {
			instance->setPlotLineWidth(_plotLineWidth);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setNeedPlotLine_bool(cv::plot::Plot2d* instance, bool _needPlotLine) {
		try {
			instance->setNeedPlotLine(_needPlotLine);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setPlotLineColor_Scalar(cv::plot::Plot2d* instance, const cv::Scalar* _plotLineColor) {
		try {
			instance->setPlotLineColor(*_plotLineColor);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setPlotBackgroundColor_Scalar(cv::plot::Plot2d* instance, const cv::Scalar* _plotBackgroundColor) {
		try {
			instance->setPlotBackgroundColor(*_plotBackgroundColor);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setPlotAxisColor_Scalar(cv::plot::Plot2d* instance, const cv::Scalar* _plotAxisColor) {
		try {
			instance->setPlotAxisColor(*_plotAxisColor);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setPlotGridColor_Scalar(cv::plot::Plot2d* instance, const cv::Scalar* _plotGridColor) {
		try {
			instance->setPlotGridColor(*_plotGridColor);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setPlotTextColor_Scalar(cv::plot::Plot2d* instance, const cv::Scalar* _plotTextColor) {
		try {
			instance->setPlotTextColor(*_plotTextColor);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_setPlotSize_int_int(cv::plot::Plot2d* instance, int _plotSizeWidth, int _plotSizeHeight) {
		try {
			instance->setPlotSize(_plotSizeWidth, _plotSizeHeight);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
	Result_void cv_plot_Plot2d_render_const__OutputArrayX(cv::plot::Plot2d* instance, const cv::_OutputArray* _plotResult) {
		try {
			instance->render(*_plotResult);
			return Ok();
		} OCVRS_CATCH(OCVRS_TYPE(Result_void))
	}
	
}
