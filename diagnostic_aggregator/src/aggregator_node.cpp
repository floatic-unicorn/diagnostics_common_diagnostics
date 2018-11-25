/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2009, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/**< \author Kevin Watts */

#include <diagnostic_aggregator/aggregator.h>
#include <exception>
#include "rclcpp/rclcpp.hpp"

using namespace std;
int main(int argc, char **argv)
{
 // ros::init(argc, argv, "diagnostic_aggregator");
  cout<< "Vaibhav diagnostic_aggregator init done "<< endl;
  rclcpp::init(argc, argv);
  try
  {
  cout<< "Vaibhav diagnostic_aggregator exception hit 1 "<< endl;
  diagnostic_aggregator::Aggregator agg;

  //ros::Rate pub_rate(agg.getPubRate());
   rclcpp::Rate  pub_rate(agg.getPubRate());
  //ros::Rate pub_rate(agg.getPubRate());
  while (agg.ok())
  {
   // ros::spinOnce();
    rclcpp::spin_some(agg.get_node());
    agg.publishData();
    pub_rate.sleep();
  }
  }
  catch (exception& e)
  {
  cout<< "Vaibhav diagnostic_aggregator exception hit  "<< endl;
   // ROS_FATAL("Diagnostic aggregator node caught exception. Aborting. %s", e.what());
   // ROS_BREAK();
  }
  
  cout<< "Vaibhav diagnostic_aggregator is going to shutdown  "<< endl;
 rclcpp::shutdown();
  return 0;
}
  
