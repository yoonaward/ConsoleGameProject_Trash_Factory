#include "LeafEffect.h"

#include <Render/Renderer.h>

#include <cassert>

using namespace Craft;

LeafEffect::LeafEffect()
	:Actor("", Vector2::Zero, Color::Green)
{
	sortingOrder = 100;
	LoadEffect("LeafEffect.txt");
}

LeafEffect::~LeafEffect()
{

}
	

void LeafEffect::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	elapsedTime += deltaTime;

	if (elapsedTime >= duration)
	{
		Destroy();
	}
}

void LeafEffect::Draw()
{
	for(int y =0; y < static_cast<int>(effectLines.size()); ++y)
	{
		Renderer::Get().Submit(effectLines[y], Vector2(0,y), Color::Brown, sortingOrder);
	}
}

void LeafEffect::LoadEffect(const std::string& filename)
{
	// 최종 경로
	std::string path = std::string("../Assets/") + filename;

	// 널 
	FILE* file = nullptr;

	// 열기
	fopen_s(&file, path.c_str(), "rt");

	// 파일이 없으면
	if (!file)
	{
		assert(false && "파일 열기 실패.");
		return;
	}
	
	// 파일의 내용 저장할 버퍼 확인
	// 파일 길이 확인
	// 뒤로 이동 후 값 읽기
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);

	// 위치 처음으로 돌리기
	rewind(file);

	// 사이즈 만큼 버퍼 생성.
	char* buffer = new char[fileSize];

	// 파일 읽기
	size_t readSize = fread(buffer, sizeof(char), fileSize, file);

	// 데이터 없을 시 어서트
	assert(readSize > 0 && "읽을 데이터가 없음.");

	// 저장된 값을 접근하기 위한 인덱스
	int index = 0;

	// 한 줄 저장용 
	std::string currentLine;

	while (true)
	{
		// 종료 조건
		if (index >= fileSize)
		{
			break;
		}

		// 이번에 확인할 문자 값
		char mapCharacter = buffer[index];

		// 확인 후 증가
		++index;

		// 한 줄이 끝나면 저장.
		if (mapCharacter == '\n')
		{
			std::vector<std::string> effectLines;
			currentLine.clear();
			continue;
		}

		if (mapCharacter == '#')
		{
			currentLine.push_back('#');
		}

		if (mapCharacter == '.')
		{
			currentLine.push_back(' ');
		}
		else
		{
			currentLine.push_back(mapCharacter);
		}
	}

	// 동적 메모리 버퍼 해제
	delete[] buffer;

	// Null
	buffer = nullptr;

	// 안전을 위한 닫기
	fclose(file);

	// NULL
	file = nullptr;

}

