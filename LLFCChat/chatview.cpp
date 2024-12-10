#include "chatview.h"
#include <QEvent>
#include <QDebug>
#include <QScrollBar>

ChatView::ChatView(QWidget* parent) : QWidget(parent), isAppended(false) {
	//垂直布局
	QVBoxLayout* pMainLayout = new QVBoxLayout();
	this->setLayout(pMainLayout);
	pMainLayout->setContentsMargins(0, 0, 0, 0);

	//设置滚动区域
	m_pScrollArea = new QScrollArea();
	m_pScrollArea->setObjectName("chat_area");
	pMainLayout->addWidget(m_pScrollArea);

	//创建聊天widget
	QWidget* w = new QWidget(this);
	w->setObjectName("chat_bg");
	w->setAutoFillBackground(true);//充满所在区域

	//创建子垂直布局
	QVBoxLayout* pHLayout_1 = new QVBoxLayout();
	pHLayout_1->addWidget(new QWidget(), 100000);
	w->setLayout(pHLayout_1);
	m_pScrollArea->setWidget(w);

	m_pScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//取消滚动条
	QScrollBar* pVScrollBar = m_pScrollArea->verticalScrollBar();//获取垂直滚动条
	//滚动条范围增加时（聊天记录条数增加时）触发
	connect(pVScrollBar, &QScrollBar::rangeChanged, this, &ChatView::onVScrollBarMoved);

	//把垂直滚动条放到上边 而不是原来的并排
	QHBoxLayout* pHLayout_2 = new QHBoxLayout();
	pHLayout_2->addWidget(pVScrollBar, 0, Qt::AlignRight);
	pHLayout_2->setContentsMargins(0, 0, 0, 0);
	m_pScrollArea->setLayout(pHLayout_2);
	pVScrollBar->setHidden(true);//隐藏滚动条

	m_pScrollArea->setWidgetResizable(true);
	m_pScrollArea->installEventFilter(this);
	initStyleSheet();
}

void ChatView::onVScrollBarMoved(int min, int max) {
	if (isAppended) //添加item可能调用多次
	{
		QScrollBar* pVScrollBar = m_pScrollArea->verticalScrollBar();
		pVScrollBar->setSliderPosition(pVScrollBar->maximum());//设置滚动条位置
		//500毫秒内可能调用多次
		QTimer::singleShot(500, [this]() {
			isAppended = false;
			});
	}
}

void ChatView::appendChatItem(QWidget* item) {
	QVBoxLayout* vl = qobject_cast<QVBoxLayout*>(m_pScrollArea->widget()->layout());
	qDebug() << "vl->count() is " << vl->count();
	vl->insertWidget(vl->count() - 1, item);//插入聊天气泡
	isAppended = true;
}

void ChatView::prependChatItem(QWidget* item) {

}

void ChatView::insertChatItem(QWidget* before, QWidget* item) {

}

void ChatView::removeAllItem() {
	QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(m_pScrollArea->widget()->layout());

	int count = layout->count();

	for (int i = 0; i < count - 1; ++i) {
		QLayoutItem* item = layout->takeAt(0); // 始终从第一个控件开始删除
		if (item) {
			if (QWidget* widget = item->widget()) {
				delete widget;
			}
			delete item;
		}
	}
}

bool ChatView::eventFilter(QObject* o, QEvent* e) {
	/*if(e->type() == QEvent::Resize && o == )
	{

	}
	else */if (e->type() == QEvent::Enter && o == m_pScrollArea) {//根据maximum()是否等于零决定是否显示滚动条
		m_pScrollArea->verticalScrollBar()->setHidden(m_pScrollArea->verticalScrollBar()->maximum() == 0);
	} else if (e->type() == QEvent::Leave && o == m_pScrollArea) {//鼠标离开则隐藏滚动条
		m_pScrollArea->verticalScrollBar()->setHidden(true);
	}
	return QWidget::eventFilter(o, e);
}

void ChatView::paintEvent(QPaintEvent* event) {
	QStyleOption opt;
	opt.initFrom(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ChatView::initStyleSheet() {

}
