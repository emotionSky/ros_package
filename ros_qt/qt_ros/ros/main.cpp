/**
 * @description: 主文件
 * @copyright: emotionsky
 * @date: 2020/12/04
 * @version: v1.0
 * @email: bitdreamsky@126.com
 */ 
#include "qttest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "qt_ros_node");
    QApplication a(argc, argv); ///< 参照qt界面标准写法
    QtTest w;
    w.show();

    return a.exec();
}
