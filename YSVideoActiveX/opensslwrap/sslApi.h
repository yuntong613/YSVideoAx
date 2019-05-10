/**	@file sslApi.h
 *	@note HangZhou Hikvision Digital Technology Co., Ltd. All Right Reserved.
 *	@brief 封装了openssl的相关接口。
 *
 *	@author		qinfengwei
 *	@date		2014/03/05
 *
 *	@version V1.7.0  
 *	@note 封装了openssl的AES、MD5、Base64、SSL接口
 *	@note 历史记录：
 *		日期     版本			   人员     事项
 *	1. 20130711 创建
 *  2. 20140305 版本修改为1.7.1   秦峰巍  增加接口RSA相关接口
 */


#ifndef _SSL_API
#define _SSL_API

#if defined (_WIN32) || defined(_WIN64)
#ifdef OPENSSLWRAP_EXPORTS
#define SSL_API	__declspec(dllexport)
#else
#define SSL_API __declspec(dllimport)
#endif

#define SSL_CALLBACK __stdcall
#else
#define SSL_API 

#define SSL_CALLBACK 
#endif


typedef enum
{
	SSL_NO_PADDING,
	SSL_ZERO_PADDING,
	SSL_PKSC5_PADDING
}PADDING_MODE;

typedef enum
{
	ECB,
	CBC
}WORK_MODE;

typedef void* HSSL_CTX;
typedef void* HSSL_SESSION;
typedef void* HRSA_CTX;

#define RSA_PUBLIC_KEY	1	//RSA 公钥
#define RSA_PRIVATE_KEY 2	//RSA 私钥

typedef enum
{
	SSL_CLIENT,
	SSL_SERVER,
}SSL_MODE;

//证书文件格式
const int SSL_FILE_TYPE_PEM = 1;
const int SSL_FILE_TYPE_ASN1 = 2;

const int SSL_RESULT_ERROR = -1;
const int SSL_RESULT_OK = 0;
const int SSL_CONNECT_FAILED = -2;
const int SSL_SEND_FAILED = -3;
const int SSL_RECV_FAILED = -4;
const int SSL_ALLOC_FAILED = -5;
const int SSL_RECV_TIMEOUT = -6; 


const int SSL_ENCRYPT_FAILED = -10;
const int SSL_DECRYPT_FAILED = -11;
const int SSL_RSPDATA_ERROR = -12;

typedef struct
{
	int cmd_type;	//信令类型
	char *msg_str;	//报文
	int msg_len;	//报文长度
	int transfer_len;//透传报文长度
}MSG_INFO;


#ifdef __cplusplus
extern "C"
{
#endif


	/**	
	 *	@brief 初始化opensslwrap库
	 *	@return	
	 *	@note	程序启动时调用ssl_init，退出时调用ssl_uninit；可多次调用，内部支持引用计数
	 */
	SSL_API void SSL_CALLBACK ssl_init();
	SSL_API void SSL_CALLBACK ssl_uninit();

	//base64
	/**	
	 *	@brief base64加解密
	 *	@param[in] src_str 源字符串地址
	 *	@param[in] src_len 源字符串长度
	 *	@param[out] encode_str 目的字符串地址，库内部申请内存，使用ssl_free_buffer释放
	 *	@param[out] encode_len 目的字符串长度
	 *	@return	SSL_RESULT_ERROR 失败 SSL_RESULT_OK 成功
	 *	@note ssl_free_buffer
	 */
	SSL_API int	SSL_CALLBACK ssl_base64_encode(const char *src_str, int src_len, char **encode_str, int *encode_len);
	SSL_API int SSL_CALLBACK ssl_base64_decode(const char *src_str, int src_len, char **decode_str, int *decode_len);


	/**	
	 *	@brief base64加解密，兼容是否有换行符
	 *	@param[in] src_str 源字符串地址
	 *	@param[in] src_len 源字符串长度
	 *	@param[out] encode_str 目的字符串地址，库内部申请内存，使用ssl_free_buffer释放
	 *	@param[out] encode_len 目的字符串长度
	 *	@param[in] new_line_flag 1-有换行符 0-无换行符
	 *	@return	SSL_RESULT_ERROR 失败 SSL_RESULT_OK 成功
	 *	@note	ssl_free_buffer
	 */
	SSL_API int	SSL_CALLBACK ssl_base64_encodeEx(const char *src_str, int src_len, char **encode_str, int *encode_len, int new_line_flag);
	SSL_API int SSL_CALLBACK ssl_base64_decodeEx(const char *src_str, int src_len, char **decode_str, int *decode_len);

	//des
	SSL_API int SSL_CALLBACK ssl_des_encrypt(const char* key, const char* src_str, int src_len, char** encrypt_str, int *encrypt_len);
	SSL_API int SSL_CALLBACK ssl_des_decrypt(const char* key, const char* src_str, int src_len, char** decrypt_str, int *decrypt_len);

	//aes
	/**	@fn	SSL_API int SSL_CALLBACK ssl_aes_encrypt(const char* key, const char* src_str, int src_len, char** encrypt_str, int *encrypt_len)
	 *	@brief AES 加密 对齐方式：PKCS5Padding ;加密模式：cbc128;vi:16字节长数组，初始化0-7：01234567
	 *	@param[in] key 16字节长度。注：必须初始化大于16字节长度的字符串数组，然后再赋值，不然会出错。例：char key[32] = {0}; sprinf(key,"123456");
	 *	@param[in] src_str 明文
	 *	@param[in] src_len 明文长度
	 *	@param[out] encrypt_str 密文,库内部申请内存，使用ssl_free_buffer释放
	 *	@param[out] encrypt_len 密文长度
	 *	@return	0 成功 -1失败
	 */
	SSL_API int SSL_CALLBACK ssl_aes_encrypt(const char* key, const char* src_str, int src_len, char** encrypt_str, int *encrypt_len);
	SSL_API int SSL_CALLBACK ssl_aes_decrypt(const char* key, const char* src_str, int src_len, char** decrypt_str, int *decrypt_len);

	//md5
	/**	
	 *	@brief md5
	 *	@param[in] msg 源字符串地址
	 *	@param[in] msg_len 源字符串长度
	 *	@param[out] md5 目的字符串地址,32长度的小写字符串
	 *	@param[out] md5_len 目的字符串长度
	 *	@return	SSL_RESULT_ERROR 失败 SSL_RESULT_OK 成功
	 *	@note	
	 */
	SSL_API int SSL_CALLBACK ssl_md5_digest(const char* msg, int msg_len, char *md5, int* md5_len);

	//free
	/**	
	 *	@brief 释放内部申请的内存地址
	 *	@param[in] buffer 内部返回的内存地址指针
	 *	@return	
	 *	@note	请使用该函数来释放库中申请的内存，否则可能会造成内存泄漏
	 */
	SSL_API void SSL_CALLBACK ssl_free_buffer(char* buffer);


	/**	
	 *	@brief 产生随机密钥
	 *	@param[in/out] key 保存密钥的字符串地址
	 *	@param[in] key_len 需要生成密钥的长度，不大于256个字节
	 *	@return	SSL_RESULT_ERROR 失败 SSL_RESULT_OK 成功
	 *	@note	
	 */
	SSL_API int SSL_CALLBACK ssl_generate_key(char *key, int key_len);

	//encrpt_type 0-none 1-aes
	/**	
	 *	@brief 生成安全协议报文
	 *	@param[in/out] packet 保存生成报文的地址
	 *	@param[in/out] packet_len 生成报文的长度
	 *	@param[in] key 加密密钥，如不需加密可传NULL
	 *	@param[in] encrpt_type 1-AES加密 0-不加密
	 *	@param[in] in_info 报文信息结构体
	 *	@return	-1失败 0成功
	 *	@note	
	 */
	SSL_API int SSL_CALLBACK ssl_generate_packet(char *packet, int *packet_len, const char *key, int encrpt_type, MSG_INFO *in_info);

	/**	
	 *	@brief 解析安全协议报文
	 *	@param[in] packet 报文的地址
	 *	@param[in] packet_len 报文的长度
	 *	@param[in] key 加密密钥，如不需加密可传NULL
	 *	@param[in] encrpt_type 1-AES加密 0-不加密
	 *	@param[out] out_info 报文信息结构体
	 *	@return	-1失败 0成功
	 *	@note	
	 */
	SSL_API int SSL_CALLBACK ssl_parse_packet(char *packet, int packet_len, const char *key, int encrpt_type, MSG_INFO *out_info);


	//建立ssl环境，程序启动和结束时调用
	SSL_API HSSL_CTX SSL_CALLBACK ssl_create(SSL_MODE type);
	SSL_API int SSL_CALLBACK ssl_destroy(HSSL_CTX hssl_handle);

	//设置证书
	SSL_API int SSL_CALLBACK ssl_set_cert(HSSL_CTX hssl_handle, const char *certificate_file, int certificate_file_type, const char *privatekey_file, int privatekey_file_type);

	//建立ssl连接
	SSL_API HSSL_SESSION SSL_CALLBACK ssl_accept(HSSL_CTX hssl_ctx, int socket);
	SSL_API HSSL_SESSION SSL_CALLBACK ssl_connect(HSSL_CTX hssl_ctx, int socket);

	//subject_name = "/C=CN/ST=BeiJing/L=BeiJing/O=MyCompany Corp./CN=www.mycompany.com/emailAddress=admin@mycompany.com"
	//issuer_name =  "/C=CN/ST=BeiJing/L=BeiJing/O=MyCompany Corp./emailAddress=admin@mycompany.com"
	SSL_API int SSL_CALLBACK ssl_verify_cert(HSSL_SESSION hssl_session, const char *subject_name, const char *issuer_name);

	//数据发送和接收
	SSL_API int SSL_CALLBACK ssl_send(HSSL_SESSION hssl_session,const char* buf, int len);
	SSL_API int SSL_CALLBACK ssl_recv(HSSL_SESSION hssl_session, char* buf, int len);
	
	//关闭ssl连接
	SSL_API int SSL_CALLBACK ssl_close(HSSL_SESSION hssl_session);

	//tcp -client encrpt_type 0-none 1-aes
	SSL_API int SSL_CALLBACK ssl_tcp_send_msg(const char *ip, unsigned int port, MSG_INFO *in_info, MSG_INFO *out_info, const char *key, bool use_ssl, int encrpt_type, int time_out);

	////https
	//SSL_API int SSL_CALLBACK ssl_https_get(const char *url, const char *auth, char *content, int *len);
	//SSL_API int SSL_CALLBACK ssl_https_put(const char *url, const char *auth, char *content, int len);

	SSL_API int SSL_CALLBACK ssl_get_detail_error(int *error_id,int *ssl_error,int *sys_error);
	SSL_API void SSL_CALLBACK SetLastDetailError(int iErrnoId,int iSSLError,int iSysError);

	//RSA
	SSL_API HRSA_CTX SSL_CALLBACK ssl_create_rsa_ctx(const char* file_name, const char* aes_key, int key_type);
	SSL_API int SSL_CALLBACK ssl_destory_rsa_ctx(HRSA_CTX hctx);
	SSL_API int SSL_CALLBACK ssl_get_rsa_type(HRSA_CTX hctx);

	SSL_API int SSL_CALLBACK ssl_rsa_encrypt(HRSA_CTX hctx, const char* src_str, int src_len, char** encrypt_str, int *encrypt_len);
	SSL_API int SSL_CALLBACK ssl_rsa_decrypt(HRSA_CTX hctx, const char* src_str, int src_len, char** decrypt_str, int *decrypt_len);

#ifdef __cplusplus
}
#endif


#endif