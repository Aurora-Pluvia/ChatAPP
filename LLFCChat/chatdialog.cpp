#include "chatdialog.h"
#include "ui_chatdialog.h"
#include <QAction>
#include <QRandomGenerator>
#include "chatuserwid.h"
#include "loadingdlg.h"

ChatDialog::ChatDialog(QWidget* parent) : QDialog(parent), ui(new Ui::ChatDialog),
_mode(ChatUIMode::ChatMode), _state(ChatUIMode::ChatMode), _b_loading(false) {//设置初始状态和模式
	ui->setupUi(this);
	ui->add_btn->SetState("normal", "hover", "press");
	ui->search_edit->SetMaxLength(15);

	QAction* searchAction = new QAction(ui->search_edit);
	searchAction->setIcon(QIcon(":/res/search.png"));
	ui->search_edit->addAction(searchAction, QLineEdit::LeadingPosition);//头部
	ui->search_edit->setPlaceholderText(QStringLiteral("搜索"));//设置默认文本

	// 创建一个清除动作并设置图标
	QAction* clearAction = new QAction(ui->search_edit);
	clearAction->setIcon(QIcon(":/res/close_transparent.png"));
	// 初始时不显示清除图标
	// 将清除动作添加到LineEdit的末尾位置
	ui->search_edit->addAction(clearAction, QLineEdit::TrailingPosition);//尾部
	// 当需要显示清除图标时，更改为实际的清除图标
	connect(ui->search_edit, &QLineEdit::textChanged, [clearAction](const QString& text) {
		if (!text.isEmpty()) {
			clearAction->setIcon(QIcon(":/res/close_search.png"));
		} else {
			clearAction->setIcon(QIcon(":/res/close_transparent.png")); // 文本为空时，切换回透明图标
		}
		});

	// 连接清除动作的触发信号到槽函数，用于清除文本
	connect(clearAction, &QAction::triggered, [this, clearAction]() {
		ui->search_edit->clear();
		clearAction->setIcon(QIcon(":/res/close_transparent.png")); // 清除文本后，切换回透明图标
		ui->search_edit->clearFocus();
		//清除按钮被按下则不显示搜索框
		ShowSearch(false);
		});
	ShowSearch(false);

	//滚轮到底之后加载更多联系人聊天记录
	connect(ui->chat_user_list, &ChatUserList::sig_loading_chat_user,
		this, &ChatDialog::slot_loading_chat_user);

	addChatUserList();//加载联系人聊天记录
}

ChatDialog::~ChatDialog() {
	delete ui;
}

//测试用临时数据
std::vector<QString> strs = { "hello world!",
"nice to meet you",
"New year, new life",
"You have to love yourself",
"My love is written in the ever since this whole world is you" };

std::vector<QString> heads = {
	":/res/head_1.jpg",
	":/res/head_2.jpg",
	":/res/head_3.jpg",
	":/res/head_4.jpg",
	":/res/head_5.jpg"
};

std::vector<QString> names = {
	"llfc",
	"zack",
	"golang",
	"cpp",
	"java",
	"nodejs",
	"python",
	"rust"
};

void ChatDialog::addChatUserList() {
	//创建QListWidgetItem，并设置自定义的widget
	for (int i = 0; i < 13; i++) {
		int randomValue = QRandomGenerator::global()->bounded(100);//生成0-99之间的随机数
		int str_i = randomValue % strs.size();
		int head_i = randomValue % heads.size();
		int name_i = randomValue % names.size();

		auto* chat_user_wid = new ChatUserWid();
		chat_user_wid->SetInfo(names[name_i], heads[head_i], strs[str_i]);//设置信息
		QListWidgetItem* item = new QListWidgetItem();
		item->setSizeHint(chat_user_wid->sizeHint());//将item大小设置成与chat_user_wid相同
		ui->chat_user_list->addItem(item);
		ui->chat_user_list->setItemWidget(item, chat_user_wid);//把item设置成自定义的组件chat_user_wid
	}
}

void ChatDialog::ShowSearch(bool bsearch) {
	if (bsearch) {//搜索模式
		ui->chat_user_list->hide();
		ui->con_user_list->hide();
		ui->search_list->show();
		_mode = ChatUIMode::SearchMode;
	} else if (_state == ChatUIMode::ChatMode) {//聊天模式
		ui->chat_user_list->show();
		ui->con_user_list->hide();
		ui->search_list->hide();
		_mode = ChatUIMode::ChatMode;
	} else if (_state == ChatUIMode::ContactMode) {//联系人模式
		ui->chat_user_list->hide();
		ui->search_list->hide();
		ui->con_user_list->show();
		_mode = ChatUIMode::ContactMode;
	}
}

void ChatDialog::slot_loading_chat_user() {
	if (_b_loading) {
		return;
	}

	_b_loading = true;
	//这样做可以保证在加载时不会阻塞
	LoadingDlg* loadingDialog = new LoadingDlg(this);
	loadingDialog->setModal(true);
	loadingDialog->show();
	qDebug() << "add new data to list...";
	addChatUserList();
	//加载完成后关闭对话框
	loadingDialog->deleteLater();

	_b_loading = false;
}
