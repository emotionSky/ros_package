/**
 * @description: 源文件
 * @copyright: emotionsky
 * @date: 2020/12/04
 * @version: v1.0
 * @email: bitdreamsky@126.com
 */
#include "qttest.h"
#include "ui_qttest.h"

QtTest::QtTest(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::QtTest)
{
    ui->setupUi(this);

    example_sub_ = n_.subscribe("/qt_ros/example1", 1, &QtTest::exampleCallback, this); ///< 标准ros接收者初始化
    example_pub_ = n_.advertise<std_msgs::Int16>("/qt_ros/example2", 1);                ///< 标准ros发布者初始化

    // 定时器相关初始化
    mpTimer = new QTimer(this);                                   ///< 指定了父对象，所以其销毁不用关心
    mpTimer->setInterval(20);                                     ///< 单位毫秒
    connect(mpTimer, &QTimer::timeout, this, &QtTest::timerLoop); ///< 定时器信号槽函数
    mpTimer->start();                                             ///< 开启定时器
}

QtTest::~QtTest()
{
    delete ui;
}

void QtTest::on_pushButton_clicked()
{
    std_msgs::Int16 info;
    info.data = ui->lineEdit->text().toInt(); ///< 类型转换和赋值
    example_pub_.publish(info);               ///< 发布消息
}

void QtTest::timerLoop()
{
    ros::spinOnce(); ///< 调用ros服务
}

void QtTest::exampleCallback(const std_msgs::Int16Ptr &msg)
{
    ui->textEdit->append(QString::number(msg->data)); ///< 显示接收的消息
}