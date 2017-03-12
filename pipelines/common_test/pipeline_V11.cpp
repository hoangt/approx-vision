#include "PipelineUtil.h"

#include <string>
#include <iostream>


// Pipeline V11 
// 
// Test type: 
// Skip only demosiac
// 
// Stages:
// Rto, Rg, Rtr, Remos, Ftr, Fg, Fto

int main(int argc, char **argv) {

  using namespace std;

  // Inform user of usage method
  if ( argc != 3 )
  {
      printf("usage: \n./convert path/to/in/image out/image/dir\n");
      return -1;
  }

  // Input image (path and name)
  char * in_img_path = argv[1];

  // Output image (just path)
  char * out_path    = argv[2];

  // Specify stages
  PipelineStageRev rev_stages[]   = { RevScale, RevToneMap, RevGamutMap, RevTransform };
  PipelineStageCV cv_stages[]     = { Remosaic };
  PipelineStageFwd fwd_stages[]   = { Transform, GamutMap, ToneMap, Descale };

  int num_stages[]  = { sizeof(rev_stages) / sizeof(rev_stages[0]), 
                        sizeof(cv_stages)  / sizeof(cv_stages[0]), 
                        sizeof(fwd_stages) / sizeof(fwd_stages[0]) }; 

  // run image pipeline with specified stages
  run_image_pipeline( in_img_path, 
                      out_path, 
                      rev_stages, 
                      cv_stages, 
                      fwd_stages, 
                      num_stages );
}
