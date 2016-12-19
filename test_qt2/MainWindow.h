#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/bn.h>
#include <openssl/ssl.h>
#include <openssl/blowfish.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

private:
	Ui::MainWindow *ui;

	int genRSA(RSA** rsa, EVP_PKEY** privateKey, int kSize);
	void freePrivateKey();

	RSA* fRsa = nullptr;
	EVP_PKEY* privateKey = nullptr;
};

#endif // MAINWINDOW_H
