#pragma once

#include <string>
#include <map>
#include <iostream>
#include <memory>
#include "Allocator.h"
#include "CLogger.h"

template<
	class ObjectT,
		template <class> class CreatorT = NewCreator,
		template <class> class DeleterT = NewDeleter>
class CacheManager : public CreatorT<ObjectT>, public DeleterT<ObjectT>
{
public:
	typedef ObjectT ObjectType;
	typedef ObjectType* ObjectPtr;
	typedef std::weak_ptr<ObjectT> ObjectWeakPtr;
	typedef std::shared_ptr<ObjectT> ObjectSharedPtr;

	CacheManager()
	{
	}

	virtual ~CacheManager()
	{
	}

	ObjectSharedPtr Load(const std::string& file_path)
	{
		Container::iterator element = container.find(file_path);
		if(element != container.end())
		{
			if(ObjectSharedPtr ptr = element->second.lock())
			{
				LOG_INFO("Already loaded : " << file_path);
				return ptr;
			}
		}

		LOG_INFO("Loading : " << file_path);
		ObjectSharedPtr ptr = std::shared_ptr<ObjectType>(Create(file_path),[=](ObjectPtr object)
		{
			LOG_INFO("Delete : " << file_path);
			Delete(object);
		});

		if(ptr)
		{
			container[file_path] = ptr;
			return ptr;
		}
		else
		{
			LOG_ERROR("Could't load " << file_path);
			return nullptr;
		}
	}

protected:
	typedef std::map<std::string, ObjectWeakPtr> Container;

	Container container;
};
