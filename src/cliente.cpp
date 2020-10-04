#include <ros/ros.h>
#include "test_servicios/mensaje_servicio.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "nodo_suma_cliente");
    ros::NodeHandle node;

    ros::ServiceClient client = node.serviceClient<test_servicios::mensaje_servicio>("servicio_suma");

    test_servicios::mensaje_servicio msj;
    msj.request.x = 3;
    msj.request.y = 4;

    client.call(msj);

    return 0;
}