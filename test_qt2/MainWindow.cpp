#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <unistd.h>
#include <QDateTime>

#define DLOGPFL qDebug() << QDateTime::currentDateTime().toString() << __LINE__;

void MainWindow::genRSA(RSA &rsa, EVP_PKEY &privateKey, int kSize)
{
	RSA* KeyPair = nullptr;
	BIGNUM* BigNumber = nullptr;
	EVP_PKEY* PrivateKey = nullptr;

	do {

		KeyPair = RSA_new();
		if (!KeyPair) {DLOGPFL; break;};

		BigNumber = BN_new();
		if (!BigNumber) {DLOGPFL; break;};

		if (!BN_set_word (BigNumber, 65537)) {DLOGPFL; break;};

		if (!RSA_generate_key_ex (KeyPair, kSize, BigNumber, NULL)) {DLOGPFL; break;};

		PrivateKey = EVP_PKEY_new();
		if (!PrivateKey) {DLOGPFL; break;};

		if (!EVP_PKEY_assign_RSA (PrivateKey, KeyPair)) {DLOGPFL; break;};

	} while(0);

	if (KeyPair) rsa = *KeyPair;
	if (PrivateKey) privateKey = *PrivateKey;

	if (BigNumber) BN_free(BigNumber);
	if (PrivateKey) { EVP_PKEY_free (PrivateKey); }
}

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	DLOGPFL
	for (int i = 0; i != 200; ++i) {
		RSA rsaCached; EVP_PKEY pkeyCached; genRSA(rsaCached, pkeyCached, 1000);
	}
	DLOGPFL
}

void MainWindow::on_pushButton_2_clicked()
{
	DLOGPFL
	RSA rsaCached; EVP_PKEY pkeyCached; genRSA(rsaCached, pkeyCached, 5500);
	DLOGPFL
}
