#include <window.hpp>
#include <iostream>
#include <string>
#include <QWidget>
#include <QIcon>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMovie>
#include <QListView>
#include <QShortcut>
#include <QDir>
using namespace std;

void Window::backDirectory() {
	// find current directory
	root.cdUp();
	fillThumbViewer();
}

void Window::nextGif(bool isForward) {
	// if no gif, set first
	if (thumbdisplayer->currentItem() == nullptr) {
		thumbdisplayer->setCurrentItem(thumbdisplayer->item(0));
		selectimageFromThumb(thumbdisplayer->item(0));
		return;
	}
	// find out which gif is active
	for (int i = 0; i < thumbdisplayer->count(); i++) {
		auto item = thumbdisplayer->item(i);
		if (item == thumbdisplayer->currentItem()) {
			int indexNextItem = i;
			if (isForward) {
				indexNextItem += 1;
			}
			else {
				indexNextItem -= 1;
			}
			if (indexNextItem >= thumbdisplayer->count()) {
				indexNextItem = 0;
			}
			if (indexNextItem < 0) {
				indexNextItem = thumbdisplayer->count() - 1;
			}
			thumbdisplayer->setCurrentItem(thumbdisplayer->item(indexNextItem));
			selectimageFromThumb(thumbdisplayer->item(indexNextItem));
			break;
		}
	}
}


// MAKING FUNCTION TO CALL ON CLICK
void Window::selectDirectory() {
	root = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		root.absolutePath(),
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	//root += "/";
	fillThumbViewer();
}

void Window::selectimageFromThumb(QListWidgetItem *item) {
	delete imagePlaceHolder->movie();
	auto fileName = item->text();
	if (fileName.endsWith(".gif")) {
		auto movie = new QMovie(root.absolutePath() + "/" + fileName);
		imagePlaceHolder->setMovie(movie);
		movie->start();
	}
	else {
		// Add picture inside the app
		QImage uploadImage(root.absolutePath() + "/" + fileName);
		//auto shrunk_logo = logoimage.scaledToHeight(40, Qt::SmoothTransformation);
		imagePlaceHolder->setPixmap(QPixmap::fromImage(uploadImage));
	}
}

void Window::fillThumbViewer() {
	thumbdisplayer->clear();
	thumbdisplayer->setViewMode(QListWidget::IconMode);
	thumbdisplayer->setIconSize(QSize(100, 100));
	QObject::connect(thumbdisplayer, &QListWidget::itemPressed, this, &Window::selectimageFromThumb);
	QDir pathobject = root;
	for (auto filename : pathobject.entryList()) {
		if (filename.endsWith(".gif")) {
			auto thumbnail = new QListWidgetItem(QIcon(root.absolutePath() + "/" + filename), filename);

			thumbdisplayer->addItem(thumbnail);
		}
	}
}

Window::Window() {
	auto mainlayout = new QVBoxLayout();

	// Customize the Window
	setStyleSheet("background:#666666;padding:5px;");
	setWindowTitle("The Amazing App");
	setWindowIcon(QIcon(QString(ROOT_PATH) + "logo.png"));
	auto topbar = new QHBoxLayout();
	setLayout(mainlayout);
	mainlayout->addLayout(topbar);

	// Add picture inside the app
	QImage logoimage(QString(ROOT_PATH) + "logo.png");
	auto shrunk_logo = logoimage.scaledToHeight(40, Qt::SmoothTransformation);
	auto logo = new QLabel();
	logo->setPixmap(QPixmap::fromImage(shrunk_logo));
	topbar->addWidget(logo);

	// Add page title
	auto title = new QLabel();
	title->setText("The Amazing App");
	title->setFixedHeight(40);
	topbar->addWidget(title);

	// Making button
	auto browse = new QPushButton();
	browse->setText("Select Directory");
	mainlayout->addWidget(browse);
	QObject::connect(browse, &QPushButton::clicked, this, &Window::selectDirectory);

	// Image placeholder
	imagePlaceHolder = new QLabel();
	mainlayout->addWidget(imagePlaceHolder);

	// Thumb displayer
	thumbdisplayer = new QListWidget();
	fillThumbViewer();
	mainlayout->addWidget(thumbdisplayer);
	

	// Creating a shortcut
	auto nextShortcut = new QShortcut(Qt::Key_Right, this);
	QObject::connect(nextShortcut, &QShortcut::activated, std::bind(&Window::nextGif, this, true));

	auto prevShortcut = new QShortcut(Qt::Key_Left, this);
	QObject::connect(prevShortcut, &QShortcut::activated, std::bind(&Window::nextGif, this, false));

	auto backspaceShortcut = new QShortcut(Qt::Key_Backspace, this);
	QObject::connect(backspaceShortcut, &QShortcut::activated,this, &Window::backDirectory);

	
	// SHOW WINDOW:
	show();
}