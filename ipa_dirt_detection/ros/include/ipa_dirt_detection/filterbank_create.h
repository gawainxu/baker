#ifndef FILTERBANK_CREATE_H_
#define FILTERBANK_CREATE_H_

#include <iostream>
#include <math.h>
#include <string.h>
#include <sstream>

#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/highgui.h>
#include <opencv2/ml/ml.hpp>
#include <cv_bridge/cv_bridge.h>

#include <eigen3/Eigen/Dense>

#include <boost/iterator/iterator_concepts.hpp>

namespace ipa_FeatureExtract
{
  /*
  class FeatureExtract
  {
  public:
    FeatureExtract(std::string input_path);
    ~FeatureExtract();
    void init();
    void preProcessing();
    void rgbToCIE(); 
    void filterBank();
    void gaussianFilter1D(double sigma, int deriv, bool hlbrt, int support, std::vector<double>& filter1D);
    void gaussianFilter2D(int ori, float sigma, bool hlbrt, double elongation);
    void rotateKernel(double ori, cv::Mat& kernel);
    double supportXRotate(double support_x, double support_y, double ori);
    double supportYRotate(double support_x, double support_y, double ori);
    void derivOris();
    
    cv::Mat input_image_;
    cv::Mat brightness_, a_, b_;
    std::vector<cv::Mat> filter_bank;
    std::vector<cv::Mat> features_;
  protected:
    
  private:
    int num_ori_;                               // number of orientations
    int num_L_bins_;                            // number of histogram of channel L
    int num_a_bins_;
    int num_b_bins_;
    double bg_smooth_sigma_;
    double cg_smooth_sigma_;
    int border_;                               // border pixels 
    double sigma_tg_filt_sm_;                  // sigma for small tg filters 
    double sigma_tg_filt_lg_;                  // sigma for large tg filters 
    
    int n_bg_;
    int n_cg_;
    int n_tg_;
    int r_bg_[];
    int r_cg_[];
    int r_tg_[];
    float sigma_;
    double oris[];                            // all the orientations of the filterbank
  };
  */
 class FilterbankCreate
 {
 public:
   FilterbankCreate(int orients, int scales, float sigma_base,double elong);
   void createKernel(cv::Mat even_kernel, cv::Mat odd_kernel);
   void createFilterBank(std::vector<cv::Mat>& filter_bank);
   double gaussianKernel(double sigma, double uv, int ord);
   void centerSorroundKernel(cv::Mat center_sorround_kernel);
   
   std::vector<cv::Mat> filters_;
 private:
   int orients_;
   int scales_;
   float sigma_base_;
   float elong_;
   double hsz_;
   int sz_;
   double sigma_;
   double c_, s_;
   double kernel_size_;
   double pi_;
   int support_;     // gaussian kernel is approximately be zeros at three times of sigma
   int mean_;
  };
};


#endif