#ifndef SIMPLE_SEGMENT_H
#define SIMPLE_SEGMENT_H

#include <iostream>
#include <string.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/string.hpp>
#include <valarray>


namespace DatasetCreate
{
  class SimpleSegment
  {
  public:
    SimpleSegment(const std::string dirt_image_path, 
		  const std::string cropped_image_path,
		  const std::string cropped_mask_path,
		  const bool background_color,
		  const int crop_residual);
    ~SimpleSegment();
    
    void run();
    void segment();
    void segement_singlechannel();
    void crop();
    void examinate();
  private:
    
    std::string dirt_image_path_;
    std::string cropped_image_path_;
    std::string cropped_mask_path_;
    bool background_color_;
    int crop_residual_;
    
    cv::Mat dirt_frame_, cropped_dirt_frame_;
    cv::Mat mask_frame_, cropped_mask_frame_;
  
  };
};


#endif