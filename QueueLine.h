#pragma once
#include <string>
#include <queue>
#include <stack>
#include "./Libraries/clsDate.h"

class QueueLine
{
public:
	class QueueLineTicket
	{
	private:
		std::string _Number = "";
		std::string _IssueTime = "";
		int _WaitingClients = 0;
		int _ServeTime = 0;

	public:
		QueueLineTicket(std::string Number, int WaitingClients, int ServeTime)
		{
			this->_Number = Number;
			this->_WaitingClients = WaitingClients;
			this->_ServeTime = ServeTime;

			this->_IssueTime = clsDate::GetSystemDateTimeString();
		}

		std::string GetNumber() { return this->_Number; }
		std::string GetIssueTime() { return this->_IssueTime; }
		int GetWaitingClients() { return this->_WaitingClients; }
		int GetServeTime() { return this->_ServeTime; }

		__declspec(property(get = GetNumber))std::string Number;
		__declspec(property(get = GetIssueTime))std::string IssueTime;
		__declspec(property(get = GetWaitingClients))int WaitingClients;
		__declspec(property(get = GetServeTime))int ServeTime;

		void Print()
		{
			cout << endl << "-----------------------------------" << endl;
			cout << "\tNumber: " << this->Number << endl << endl;
			cout << "\t" << this->IssueTime << endl;
			cout << "\tWaiting Clients - " << this->WaitingClients << endl;
			cout << "\tServe Time In - \n" << "\t\t" << this->ServeTime << " Minutes" << endl;
			cout << "-----------------------------------" << endl;
		}
	};

private:
	queue<QueueLineTicket> _QueueLine;
	std::string _Prefix = "";
	int _AvgServeTime = 0;
	int _TotalTickets = 0;

	int _GetWaitingClients()
	{
		return this->_TotalTickets - this->_GetServedClients();
	}
	int _GetServedClients()
	{
		return this->_TotalTickets - _QueueLine.size();
	}

	std::string _GetNewTicketnumber()
	{
		return this->_Prefix + to_string(_TotalTickets + 1);
	}
	int _GetNextTicketServeTime()
	{
		return this->_GetWaitingClients() * this->_AvgServeTime;
	}
public:

	QueueLine(std::string Prefix, int AvgServeTime)
	{
		this->_Prefix = Prefix;
		this->_AvgServeTime = AvgServeTime;
		this->_TotalTickets = 0;
	}

	void IssueTicket()
	{
		QueueLineTicket Ticket(this->_GetNewTicketnumber(), this->_TotalTickets, this->_GetNextTicketServeTime());
		_QueueLine.push(Ticket);

		_TotalTickets++;
	}
	bool ServeNextClient()
	{
		if (_QueueLine.empty())
			return false;

		_QueueLine.pop();
		return true;
	}

	void PrintInfo()
	{
			cout << endl << "-----------------------------------" << endl;
			cout << "\tPrefix: " << this->_Prefix << endl << endl;
			cout << "\tTotal Tickets - " << this->_TotalTickets << endl;
			cout << "\tWaiting Clients - " << this->_GetWaitingClients() << endl;
			cout << "\tServed Clients - " << this->_GetServedClients() << endl;
			cout << "-----------------------------------" << endl;
	}
	void PrintTicketsLineRTL()
	{
		cout << endl;
		if (_QueueLine.empty())
			cout << "Tickets: No Tickets.";
		else
			cout << "Tickets: ";

		queue <QueueLineTicket> TempQueueLine = _QueueLine;
		while (!TempQueueLine.empty())
		{
			QueueLineTicket Ticket = TempQueueLine.front();

			cout << " " << Ticket.Number << " <-- ";

			TempQueueLine.pop();
		}
		cout << endl;
	}
	void PrintTicketsLineLTR()
	{
		cout << endl;
		if (_QueueLine.empty())
			cout << "Tickets: No Tickets.";
		else
			cout << "Tickets: ";

		//we copy the queue in order not to lose the original
		queue <QueueLineTicket> TempQueueLine = _QueueLine;
		stack <QueueLineTicket> TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStackLine.empty())
		{
			QueueLineTicket Ticket = TempStackLine.top();

			cout << " " << Ticket.Number << " --> ";

			TempStackLine.pop();
		}
		cout << endl;
	}
	void PrintAllTickets()
	{
		cout << endl;
		cout << "---Tickets---";
		if (_QueueLine.empty())
		{
			cout << "-- - No Tickets-- - \n";
			return;
		}

		queue <QueueLineTicket> TempQueueLine = _QueueLine;
		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}
	}
};
