/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <yabou-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:11:29 by yabou-da          #+#    #+#             */
/*   Updated: 2026/06/21 19:30:30 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(int port, std::string password) : _port(port), _password(password), _socketFd(-1){}

Server::Server(const Server &obj)
{
	*this=obj;
}

Server &Server::operator=(const Server &obj)
{
	if(this != &obj)
	{
		this->_port = obj._port;
		this->_password = obj._password;
		this->_socketFd = obj._socketFd;
		this->_poolVec = obj._pollVec;
		//this->_clients = obj._clients;
		//this->_channel = obj._channel;
	}
	return(*this);
}

Server::~Server(){}

void Server::initNetwork()
{
	this->_socketFd = socket(AF_INET, SOCK_STREAM, 0);
	if(this->_socketFd == -1)
		throw Server::SocketCreationException();
	std::cout<<"listening socket creation : OK! (fd : "<<_socketFd<<")"<< std::endl;
}

// void Server::startLoop()
// {
// 	poll(_pollVec);
	
// }