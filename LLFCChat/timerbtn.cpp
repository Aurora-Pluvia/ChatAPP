#include "timerbtn.h"
#include <QMouseEvent>
#include <QDebug>

TimerBtn::TimerBtn(QWidget* parent) :QPushButton(parent), _counter(10) {
	_timer = new QTimer(this);

	//超时触发计时器，计时十秒
	connect(_timer, &QTimer::timeout, [this]() {
		_counter--;
		if (_counter <= 0) {
			_timer->stop();
			_counter = 10;
			this->setText("获取");
			this->setEnabled(true);
			return;
		}
		this->setText(QString::number(_counter));
		});
}

TimerBtn::~TimerBtn() {
	_timer->stop();
}

void TimerBtn::mouseReleaseEvent(QMouseEvent* e) {
	if (e->button() == Qt::LeftButton) {
		//左键释放
		qDebug() << "MyButton was released!";
		this->setEnabled(false);
		this->setText(QString::number(_counter));
		_timer->start(1000);
		emit clicked();//发出点击信号，继承自基类
	}
	//调用积累的mouseReleaseEvent以确保正常的事件处理
	QPushButton::mouseReleaseEvent(e);
}
