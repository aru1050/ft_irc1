/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <yabou-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:14:42 by yabou-da          #+#    #+#             */
/*   Updated: 2026/06/21 19:24:29 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP
#include <iostream>
#include <vector>
#include <poll.h>
#include <map>
#include <cstring>
#include <sys/socket.h>
#include <exception>

//class Client;
//class Channel;

class Server
{
	private:
		int								_port;
		std::string						_password;
		int								_socketFd;
		std::vector<struct pollfd>		_pollVec;
		//std::map<int, Client>			_clients;
		//std::map<std::string, Channel>	_channel;
	public:
				Server(int port, std::string password);
				Server(const Server &obj);
		Server	&operator=(const Server &obj);
				~Server();
		
		void	initNetwork();
		void 	startLoop();
		class SocketCreationException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
					return("Error : socket creation failed");
				}
		};
};

#endif