#pragma once

#include <unordered_map>


template<typename IdType, typename StringType>
struct SimpleFileInfo
{
    IdType        fileId;
    StringType    orgFilename;

}; // struct SimpleFileInfo


template<typename IdType, typename StringType>
class SimpleFilenameSet
{
    // IdType  fileId;

public:

    using FileInfoType   = SimpleFileInfo<IdType, StringType>;
    using file_info_type = FileInfoType;
    using id_type        = IdType;
    using string_type    = StringType;


protected:

    std::unordered_map<IdType, FileInfoType>       idToInfoMap;
    std::unordered_map<StringType, FileInfoType>   nameToInfoMap;


public:

    id_type getFileId(const StringType &fname)
    {
        typename std::unordered_map<StringType, FileInfoType>::const_iterator it = nameToInfoMap.find(fname);
        if (it!=nameToInfoMap.end())
        {
            return it->second.fileId;
        }

        FileInfoType fi;
        fi.fileId = nameToInfoMap.size();
        fi.orgFilename = fname;

        idToInfoMap[fi.fileId] = fi;
        nameToInfoMap[fname]   = fi;
    }

    const file_info_type* getFileInfo(id_type id)
    {
        typename std::unordered_map<IdType, FileInfoType>::const_iterator it = idToInfoMap.find(id);
        if (it==idToInfoMap.end())
            return 0;

        return &it->second;
    }


}; // class SimpleFilenameSet

        // auto pFileInfo = pFilenameSet->getFileInfo(textPos.fileId);
        // UMBA_ASSERT(pFileInfo!=0);
        // curFile = pFileInfo->orgFilename;

