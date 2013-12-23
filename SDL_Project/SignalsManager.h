#pragma once

#include <vector>
#include <boost/signals2.hpp>

class SignalsManager
{
protected:
	typedef std::pair<boost::signals2::connection, boost::signals2::shared_connection_block> Connection;
	typedef std::vector<Connection> Connections;

	virtual void AddConnection(const boost::signals2::connection& connection)
	{
		Connection pair = std::make_pair(connection, boost::signals2::shared_connection_block(connection, false));
		connections_.push_back(pair);
	}

	virtual void Block()
	{
		std::for_each(connections_.begin(), connections_.end(), [=](Connections::value_type& element)
		{
			if (!element.first.blocked())
			{
				element.second.block();
			}
		});
	}

	virtual void UnBlock()
	{
		std::for_each(connections_.begin(), connections_.end(), [=](Connections::value_type& element)
		{
			if (element.first.blocked())
			{
				element.second.unblock();
			}
		});
	}

	virtual void Disconnect()
	{
		std::for_each(connections_.begin(), connections_.end(), [=](Connections::value_type& element)
		{
			if(element.first.connected())
			{
				element.first.disconnect();
			}
		});
	}

	SignalsManager()
	{
	}

	virtual ~SignalsManager()
	{
		Disconnect();
	}

private:
	Connections connections_;
};