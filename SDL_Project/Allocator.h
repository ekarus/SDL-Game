#pragma once

template<typename T>
class NewCreator
{
public:
	static T* Create()
	{
		return new T();
	}

	template<typename T0>
	static T* Create(T0 arg0)
	{
		return new T(arg0);
	}

	template<typename T0, typename T1>
	static T* Create(T0 arg0, T1 arg1)
	{
		return new T(arg0, arg1);
	}

	template<typename T0, typename T1, typename T2>
	static T* Create(T0 arg0, T1 arg1, T2 arg2)
	{
		return new T(arg0, arg1, arg2);
	}
};

template<typename T>
class NewDeleter
{
public:
	static void Delete(T* t)
	{
		if(t)
		{
			delete t;
			t = nullptr;
		}
	}
};
