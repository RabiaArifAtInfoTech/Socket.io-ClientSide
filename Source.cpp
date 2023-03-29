#include<iostream>
#include"sio_client.h"
#include "sio_socket.h"
#include"sio_message.h"

int main()
{
	sio::client cl;

	cl.connect("http://localhost:3000/");

	std::string msg = "test message from client";

	int arr[5] = { 1, 2, 3, 4, 5 };
	//cl.socket()->emit("chat message", 1, "2", { 3: '4', 5 : Buffer.from([6]) }););
	//cl.socket()->emit("chat message", msg, arr);
	cl.socket()->emit("chat message", msg);
	
//	std::cout << "\nSocket ID :" << cl.get_sessionid() << std::endl;


	cl.socket()->on("chat message" , sio::socket::event_listener_aux([&](std::string const& name, sio::message::ptr const& data, bool isAck, sio::message::list& ack_resp)
	{
		
	//std::string arr[3];
	int arr[3];
	
	std::cout << "message from server: " << data->get_string();
	
	//std::cout << "message form server: " << data->get_int();

	
	}));
	

	getchar();


	return 0;
}