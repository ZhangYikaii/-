#include <iostream>
#include <cstring>
#include<ctime>
#include <winsock2.h>
#include <Windows.h>
#include <string>
#define max 20480

using namespace std;
#pragma comment(lib, "ws2_32.lib")

// ȫ�ֱ���
char host[500] = "elite.nju.edu.cn";
char buf[1024];

int num = 1;
string allHtml;

int ignoreTimes = 1;     // ������Ϣ����Ƶ�ʣ�ĿǰĬ��ÿ����1000�ν���һ��
SOCKET sock;

bool isLogin = false;
bool isCookie = false;

int main_time;
int init_sec;     // ��ʱ��ʼ�ĳ�ʼʱ�� 
int tot_sec;     // ��ʱ
int tot_sec_main;     // ��ʱ

char recv_buf[1024];


// "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n"
// "Accept-Encoding:gzip, deflate\r\n"
// "Accept-Language: zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7\r\n"
// "Cache-Control: max-age=0\r\n"
// "Connection: keep-alive\r\n"
// "Content-Length: 67\r\n"
// "Content-Type: application/x-www-form-urlencoded\r\n"
// "Cookie: JSESSIONID=8166CA185A2D3E197370FC0B6B4852DD; UM_distinctid=166167048ea18a-0c681cdffbfd1-9393265-144000-166167048eb5bf; yunsuo_session_verify=1649c2fee6397754b2ff79c214ab3a70; ARRAffinity=6fa7b13373a5ee8e6661f236243ccce8c95be8601d00a2d65967e5835fbd0d3e; user_id="171840708 1551077278257"\r\n"
// "Host: elite.nju.edu.cn\r\n"
// "Origin: http://elite.nju.edu.cn\r\n"
// "Referer: http://elite.nju.edu.cn/jiaowu/\r\n"
// "Upgrade-Insecure-Requests: 1\r\n"
// "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36\r\n"


// ��¼����(Request Headers)
string request_login =
"POST / jiaowu / login.do HTTP / 1.1\r\n"
"Host: elite.nju.edu.cn\r\n"
"Connection: keep-alive\r\n"
"Content-Length: 67\r\n"
"Cache-Control: max-age=0\r\n"
"Origin: http://elite.nju.edu.cn\r\n"
"Upgrade-Insecure-Requests: 1\r\n"
"Content-Type: application/x-www-form-urlencoded\r\n"
"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36\r\n"
"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n"
"Referer: http://elite.nju.edu.cn/jiaowu/exit.do\r\n"
"Accept-Encoding: gzip, deflate\r\n"
"Accept-Language: zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7\r\n"
"Cookie: JSESSIONID=273B456DB8E016B1117B54F73D957619; UM_distinctid=166167048ea18a-0c681cdffbfd1-9393265-144000-166167048eb5bf; yunsuo_session_verify=1649c2fee6397754b2ff79c214ab3a70; ARRAffinity=6fa7b13373a5ee8e6661f236243ccce8c95be8601d00a2d65967e5835fbd0d3e; user_id=\"171840708 1551080348234\"\r\n"
"\r\n"
"\r\n"
"userName=171840708&password=Zyk666&returnUrl=null&ValidateCode=";

//// ����ѡ�ν����������Ϣ(Request Headers)
//string request_choose_course =
//"GET /jiaowu/student/elective/courseList.do?method=openRenewCourseList HTTP/1.1"
//"Host: elite.nju.edu.cn"
//"Connection: keep-alive"
//"Upgrade-Insecure-Requests: 1"
//"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36"
//"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8"
//"Referer: http://elite.nju.edu.cn/jiaowu/student/select/renewindex.do"
//"Accept-Encoding: gzip, deflate"
//"Accept-Language: zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7"
//"Cookie: JSESSIONID=99DF30261CFD17CEA9D386C2E09AC3A0; UM_distinctid=166167048ea18a-0c681cdffbfd1-9393265-144000-166167048eb5bf; yunsuo_session_verify=1649c2fee6397754b2ff79c214ab3a70; ARRAffinity=6fa7b13373a5ee8e6661f236243ccce8c95be8601d00a2d65967e5835fbd0d3e; user_id=\"171840708 1551080348234\"";

string request_choose_course =
"GET /jiaowu/student/elective/courseList.do?method=openRenewCourse&campus=%E5%85%A8%E9%83%A8%E6%A0%A1%E5%8C%BA&academy=12 HTTP/1.1"
"Host: elite.nju.edu.cn"
"Connection: keep-alive"
"Upgrade-Insecure-Requests: 1"
"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36"
"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8"
"Referer: http://elite.nju.edu.cn/jiaowu/student/elective/courseList.do?method=openRenewCourseList"
"Accept-Encoding: gzip, deflate"
"Accept-Language: zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7"
"Cookie: JSESSIONID=99DF30261CFD17CEA9D386C2E09AC3A0; UM_distinctid=166167048ea18a-0c681cdffbfd1-9393265-144000-166167048eb5bf; yunsuo_session_verify=1649c2fee6397754b2ff79c214ab3a70; ARRAffinity=6fa7b13373a5ee8e6661f236243ccce8c95be8601d00a2d65967e5835fbd0d3e; user_id=\"171840708 1551080348234\"";

// Ҫ���ĿΣ�����ԭ��
string request_compilers_principles = "";


// ����
void grabCourse(){
	/*����Winsock*/
	WSADATA wd;
	WSAStartup(MAKEWORD(2, 2), &wd);
	// SOCKET temp = socket(AF_INET, SOCK_STREAM, 0);  

	/*����socket*/
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET){
		cout << "����socketʧ�ܣ� �����룺 " << WSAGetLastError() << endl;
		return;
	}

	/*�󶨣������ص�ַ ���ӵ� �׽����� �Ա��ܹ���Ч�ر�ʶ�׽���*/
	sockaddr_in sa = { AF_INET };    // �׽��ֵ�ַ��AF _!NET ����ʾ��socketλ��Internet��
	int n = bind(sock, (sockaddr*)&sa, sizeof(sa));
	if (n == SOCKET_ERROR){
		cout << "��ʧ�ܣ� �����룺 " << WSAGetLastError() << endl;
		return;
	}

	hostent *p = gethostbyname(host);
	if (p == NULL) {
		cout << "�����޷�������ip! ������룺 " << WSAGetLastError() << endl;
		return;
	}
	sa.sin_port = htons(80);
	memcpy(&sa.sin_addr, p->h_addr, 4);//    with some problems ???

	/*���ӣ����ͻ���Ҫ�������еķ�������������ʱ����Ҫ����connect ����*/
	n = connect(sock, (sockaddr*)&sa, sizeof(sa));
	if (n == SOCKET_ERROR)	{
		cout << "����ʧ�ܣ� �����룺 " << WSAGetLastError() << endl;
		return;
	}

	if (isLogin == false){
		/*��¼����ϵͳ*/
		if (isCookie == false){
			isCookie = true;
		}

		string verification_code = "";                    // ��֤��
		cout << "��������֤��: ";
		cin >> verification_code;

		string request_login_full = request_login + verification_code;

		cout << "��ʼ����¼����(Request Headers)�������Է�������..." << endl;
		if (send(sock, request_login_full.c_str(), request_login_full.size(), 0) == SOCKET_ERROR){
			cout << "����ʧ��! ������룺 " << WSAGetLastError() << endl;
			closesocket(sock);
			return;
		}
		else{
			cout << "���ͳɹ�!" << endl;
		}

		recv(sock, buf, sizeof(buf)-1, 0);
		cout << "�����Ƿ���������Ӧ��Ϣ(Response Headers)" << endl;
		printf("%s", buf);
		cout << endl;


		/*����ѡ��ϵͳ*/
		cout << "��ʼ������ѡ�ν����������Ϣ(Request Headers)�������Է�������..." << endl;
		if (send(sock, request_choose_course.c_str(), request_choose_course.size(), 0) == SOCKET_ERROR){
			cout << "����ʧ��! ������룺 " << WSAGetLastError() << endl;
			closesocket(sock);
			return;
		}
		else{
			cout << "���ͳɹ�!" << endl;
		}

		if (recv(sock, buf, sizeof(buf)-1, 0) > 0){
			cout << endl << "�����Ƿ���������Ӧ��Ϣ(Response Headers)" << endl;
			printf("%s", buf);
			cout << endl;
		}


		// system("pause");
		isLogin = true;
	}

	// ��ʼ����
	init_sec = time(0);   // ��ʱ��ʼ
	int count_num = 0;

	/*ѭ������*/
	while (true){
		// ÿһ�ζ����½�������
		SOCKET temp = socket(AF_INET, SOCK_STREAM, 0);
		sock = temp;
		if (sock == INVALID_SOCKET){
			cout << "����socketʧ�ܣ� ������룺 " << WSAGetLastError() << endl;
			return;
		}

		sockaddr_in sa = { AF_INET };

		struct hostent *p = gethostbyname(host);
		if (p == NULL){
			cout << "�����޷�������ip! ������룺 " << WSAGetLastError() << endl;
			return;
		}
		sa.sin_port = htons(80);
		memcpy(&sa.sin_addr, p->h_addr, 4);

		/*���ӣ����ͻ���Ҫ�������еķ�������������ʱ����Ҫ����connect ����*/
		n = connect(sock, (sockaddr*)&sa, sizeof(sa));
		if (n == SOCKET_ERROR)	{
			cout << "����ʧ�ܣ� ������룺 " << WSAGetLastError() << endl;
			return;
		}

		count_num++;
		tot_sec = time(0) - init_sec;
		tot_sec_main = time(0) - main_time;

		// ���Σ�����ԭ��
		cout << "��ʼ������ԭ��ѡ������(Request Headers)�������Է�������..." << endl;
		if (send(sock, request_compilers_principles.c_str(), request_compilers_principles.size(), 0) == SOCKET_ERROR){
			cout << "����ʧ��! ������룺 " << WSAGetLastError() << endl;
			grabCourse();  // �ݹ�

			return;
		}
		else{
			cout << "���ͳɹ�" << endl;
		}

		if (count_num % ignoreTimes == 0){
			if (recv(sock, recv_buf, sizeof(recv_buf)-1, 0) > 0){
				cout << endl << "�����Ƿ���������Ӧ��Ϣ(Response Headers)" << endl;
				printf("%s", recv_buf);
			}
		}

		cout << "���������ܼ�ʱ��(��λ����)��" << tot_sec_main << endl;
		cout << "����ѭ��ʱ��(��λ����)��" << tot_sec << endl;
		cout << "ִ�д�����" << count_num << endl;
		cout << "ƽ��ÿ��ִ�д�����" << (double)count_num / tot_sec << endl;

		closesocket(temp);
	}
}

int main(){
	main_time = time(0);  // ��ʼ��ʱ
	grabCourse();
	// system("pause");
	return 0;
}
