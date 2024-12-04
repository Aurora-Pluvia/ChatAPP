#pragma once
#include "BubbleFrame.h"
#include <QHBoxLayout>
#include <QPixmap>

/******************************************************************************
 *
 * @file       picturebubble.h
 * @brief      图片消息气泡
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class PictureBubble : public BubbleFrame {
	Q_OBJECT
public:
	PictureBubble(const QPixmap& picture, ChatRole role, QWidget* parent = nullptr);
};

