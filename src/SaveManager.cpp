#include "SaveManager.h"

#include <fstream>

#include "BotData.h"
#include "JsonSerializer.h"

SaveManager::SaveManager(std::string filePath, BotData& data): m_SaveFilePath(std::move(filePath)), m_Data(data)
{
	m_Serializer = std::make_unique<JsonSerializer>();
}

void SaveManager::Save() const
{
	std::ofstream os(m_SaveFilePath, std::ofstream::out);
	m_Serializer->Serialize(m_Data, os);
	os.close();
}

void SaveManager::Load() const
{
	if (std::ifstream is(m_SaveFilePath); is.good()) // does file exists ?
	{
		m_Serializer->UnSerialize(is, m_Data);
		is.close();
	}
}
