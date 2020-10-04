#include <ros/ros.h>
#include "test_servicios/mensaje_servicio.h"

bool suma(test_servicios::mensaje_servicioRequest &req, test_servicios::mensaje_servicioResponse &res){
  res.sum = req.x + req.y;
  ROS_INFO("La suma es: %d", res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "nodo_suma_servicio");
  ros::NodeHandle node;

  ros::ServiceServer service = node.advertiseService("servicio_suma", suma);
  
  ros::spin();

  return 0;
}