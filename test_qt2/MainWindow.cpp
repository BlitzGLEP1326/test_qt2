#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <unistd.h>
#include <QDateTime>
#include <QTextStream>

static QTextStream ts{stderr};
#define DLOGPFL ts << QDateTime::currentDateTime().toString() << __LINE__ << "\n"; ts.flush();

int MainWindow::genRSA(RSA** rsa, EVP_PKEY** privateKey, int kSize)
{
	RSA* Rsa = nullptr;
	BIGNUM* BigNumber = nullptr;
	EVP_PKEY* PrivateKey = nullptr;
	int res = -1;

	do {

		Rsa = RSA_new();
		if (!Rsa) {DLOGPFL; break;};
		res = -2; // Rsa not in PrivateKey

		BigNumber = BN_new();
		if (!BigNumber) {DLOGPFL; break;};

		if (!BN_set_word (BigNumber, 65537)) {DLOGPFL; break;};

		if (!RSA_generate_key_ex (Rsa, kSize, BigNumber, NULL)) {DLOGPFL; break;};

		PrivateKey = EVP_PKEY_new();
		if (!PrivateKey) {DLOGPFL; break;};
		res = -3;

		if (!EVP_PKEY_assign_RSA (PrivateKey, Rsa)) {DLOGPFL; break;}; // Rsa in PrivateKey
		res = 0;

	} while(0);

	if (BigNumber) BN_free(BigNumber);

	if (!res) {
		*rsa = Rsa;
		*privateKey = PrivateKey;
	} else {
		if (PrivateKey) { DLOGPFL; EVP_PKEY_free(PrivateKey); }
		if (Rsa && res == -2) { DLOGPFL; RSA_free(Rsa); }
		*rsa = nullptr;
		*privateKey = nullptr;
	}

	return res;
}

void MainWindow::freePrivateKey()
{
	if (privateKey) EVP_PKEY_free(privateKey);
}

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

}

MainWindow::~MainWindow()
{
	freePrivateKey();
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	DLOGPFL
	for (int i = 0; i != 20; ++i) {
		freePrivateKey();
		genRSA(&fRsa, &privateKey, 1000);
	}
	DLOGPFL
}

void MainWindow::on_pushButton_2_clicked()
{
	DLOGPFL
	freePrivateKey();
	genRSA(&fRsa, &privateKey, 1000);
	DLOGPFL
}
