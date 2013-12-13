#pragma once
#include "Allocator.h"

template
	<
	class ObjectT,
	template <class> class CreatorT = NewCreator,
	template <class> class DeleterT = NewDeleter
	>
class Singleton : public CreatorT<ObjectT>, public DeleterT<ObjectT>
{
public:
	typedef ObjectT ObjectType;
	typedef ObjectType* ObjectPtr;

	static ObjectT* Instance()
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

	template<typename T0>
	static ObjectT* Instance(T0 arg0)
	{
		if(inst_)
		{
			return inst_;
		}
		else
		{
			return inst_ = Create(arg0);
		}
	}

	template<typename T0, typename T1>
	static ObjectT* Instance(T0 arg0, T1 arg1)
	{
		if(inst_)
		{
			return inst_;
		}
		else
		{
			return inst_ = Create(arg0, arg1);
		}
	}

	template<typename T0, typename T1, typename T2>
	static ObjectT* Instance(T0 arg0, T1 arg1, T2 arg2)
	{
		if(inst_)
		{
			return inst_;
		}
		else
		{
			return inst_ = Create(arg0, arg1, arg2);
		}
	}

	static void Delete()
	{
		DeleterT<ObjectT>::Delete(inst_);
	}

private:
	static ObjectT* inst_;
	Singleton& operator=(const Singleton& base);
	Singleton(const Singleton& base);

protected:
	Singleton(){}
	virtual ~Singleton(){}
};

template<
	class ObjectT,
	template <class> class CreatorT /*= NewCreator*/,
	template <class> class DeleterT /*= NewDeleter*/>
ObjectT* Singleton<ObjectT, CreatorT, DeleterT>::inst_ = nullptr;
