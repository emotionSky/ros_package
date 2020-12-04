/**
 * @description: 头文件
 * @copyright: emotionsky
 * @date: 2020/12/04
 * @version: v1.0
 * @email: bitdreamsky@126.com
 */
#ifndef QTTEST_H
#define QTTEST_H

#include <QMainWindow>
#include <QTimer> ///< 定时器
#include <QDebug> ///< 输出打印

// ros
#include <ros/ros.h>
#include <std_msgs/Int16.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class QtTest;
}
QT_END_NAMESPACE

class QtTest : public QMainWindow
{
    Q_OBJECT

public:
    QtTest(QWidget *parent = nullptr);
    ~QtTest();

    void timerLoop();                                    ///< 定时器槽函数
    void exampleCallback(const std_msgs::Int16Ptr &msg); ///< 消息回调函数

private slots:
    void on_pushButton_clicked(); ///< 按键槽函数

private:
    Ui::QtTest *ui;

    // ros
    ros::NodeHandle n_;
    ros::Subscriber example_sub_; ///< 接收者
    ros::Publisher example_pub_;  ///< 发布者

    QTimer *mpTimer; ///< 定时器
};
#endif // QTTEST_H
