#pragma once

template<typename Base>
class Singleton
{
public:

	static Base* Instance()
	{
		if(inst_)
		{
			return inst_;
		}
		else
		{
			return inst_ = Create();
		}
	}

	void DeleteInstance()
	{
		if(inst_)
		{
			delete inst_;
			inst_=nullptr;
		}
	}

private:

	static Base* Create()
	{
		return  new Base();
	}

	static Base* inst_;

	Singleton& operator=(const Singleton& base);
	Singleton(const Singleton& base);

protected:

	Singleton()
	{
	}

	virtual ~Singleton()
	{
	}
};

template<typename Base >
Base* Singleton<Base>::inst_ = nullptr;
