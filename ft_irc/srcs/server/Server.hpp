/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <yabou-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:14:42 by yabou-da          #+#    #+#             */
/*   Updated: 2026/06/21 17:00:20 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP
#include <iostream>
#include <vector>
#include <poll.h>
#include <map>
#include <cstring>

class Client;
class Channel;

class Server
{
	private:
		int								_port;
		std::string						_password;
		int								_socketFd;
		std::vector<struct pollfd>		_poolVec;
		std::map<int, Client>			_clients;
		std::map<std::string, Channel>	_channel;
	public:
		Server(int port, std::string password);
		Server(const Server &obj);
		Server	&oprator=(const Server &obj);
		~Server();
};

#endif