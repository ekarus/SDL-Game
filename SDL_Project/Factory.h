/*
#pragma once

#include "Allocator.h"
#include <boost/shared_ptr.hpp>

template<
	class ObjectT,
		template <class> class CreatorT = NewCreator,
		template <class> class DeleterT = NewDeleter>
class Factory
{
public:

	typedef ObjectT ObjectType;
	typedef boost::shared_ptr<ObjectType> ObjectPtr;

	static ObjectPtr Create()
	{
		ObjectType* raw_ptr = CreatorT<ObjectType>::Create();
		return ObjectPtr(raw_ptr);
	}

	template<typename T0>
	static ObjectPtr Create(T0 arg0)
	{
		ObjectType* raw_ptr = CreatorT<ObjectType>::Create(arg0);
		return ObjectPtr(raw_ptr);
	}

	template<typename T0, typename T1>
	static ObjectPtr Create(T0 arg0, T1 arg1)
	{
		ObjectType* raw_ptr = CreatorT<ObjectType>::Create(arg0, arg1);
		return ObjectPtr(raw_ptr);
	}

	template<typename T0, typename T1, typename T2>
	static ObjectPtr Create(T0 arg0, T1 arg1, T2 arg2)
	{
		ObjectType* raw_ptr = CreatorT<ObjectType>::Create(arg0, arg1, arg2);
		return ObjectPtr(raw_ptr);
	}
};

template
	<
	class BaseObjectT, class DerivedObjectT,
		template <class> class CreatorT = NewCreator,
		template <class> class DeleterT = NewDeleter
	>
class ObjectFactory
{
public:

	typedef BaseObjectT ObjectType;
	typedef DerivedObjectT DerivedObject;
	typedef boost::shared_ptr<ObjectType> ObjectPtr;

	virtual ObjectPtr Create()
	{
		ObjectType* raw_ptr = CreatorT<DerivedObject>::Create();
		return ObjectPtr(raw_ptr);
	}

	template<typename T0>
	virtual ObjectPtr Create(T0 arg0)
	{
		ObjectType* raw_ptr = CreatorT<DerivedObject>::Create(arg0);
		return ObjectPtr(raw_ptr);
	}

	template<typename T0, typename T1>
	virtual ObjectPtr Create(T0 arg0, T1 arg1)
	{
		ObjectType* raw_ptr = CreatorT<DerivedObject>::Create(arg0, arg1);
		return ObjectPtr(raw_ptr);
	}

	template<typename T0, typename T1, typename T2>
	virtual ObjectPtr Create(T0 arg0, T1 arg1, T2 arg2)
	{
		ObjectType* raw_ptr = CreatorT<DerivedObject>::Create(arg0, arg1, arg2);
		return ObjectPtr(raw_ptr);
	}
};*/