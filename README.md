# taxi-order-simulation
A taxi-hailing app(driver client) simulation based on Qt.  Mainly used in driving simulation experiment.

开发与2017年3月，用于学校内的心理学研究的接单模拟app。

实验场景是驾驶过程中接单的司机，该app的功能是发送随机订单信息（随机顺序及各订单信息提前写在文件中，包括音频），司机可以选择接单、拒接或忽视。

订单在一定时间后会消失，订单之间的屏幕会显示一张图片（用于代替地图）。

app会记录司机的操作（从订单出现到司机按下的时间），没有操作则做特殊记录。

代码使用C++完成，主要使用Qt GUI模块。
