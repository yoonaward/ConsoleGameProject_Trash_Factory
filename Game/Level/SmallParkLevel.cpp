#include "SmallParkLevel.h"
#include <Actor/Player.h>
#include <Actor/Tree.h>
#include <Actor/Ground.h>
#include <Actor/Water.h>
#include <Actor/Garbage.h>
#include <Actor/TrashCan.h>
#include <Actor/Obstacle.h>


#include <cassert>

using namespace Craft;

SmallParkLevel::SmallParkLevel()
{
}

SmallParkLevel::~SmallParkLevel()
{
}

void SmallParkLevel::OnInitialized()
{
    // 먼저 부모 레벨 초기화
    super::OnInitialized();

    // 이 레벨에서 사용할 맵 불러오기
    LoadMap("SmallParkMap.txt");

	// 플레이어 임시 스폰
	SpawnActor<Player>();
	
}

void SmallParkLevel::LoadMap(const std::string& filename)
{
		// 경로 조립 ( 상대 경로 지정 )
		std::string path = std::string("../Assets/") + filename;

		// 파일 열기 ( c 스타일로 오픈 )
		// 초기화 진행
		FILE* file = nullptr;

		// 파일 오픈
		fopen_s(&file, path.c_str(), "rt");

		// 오류 처리
		if (!file)
		{
			assert(false && "failed to open a Stage file.");
			return;
		}

		// 텍스트 파일 위치를 뒤로 이동 시켜, 해당 위치 값 읽기
		fseek(file, 0, SEEK_END);

		// 파일 길이 확인
		long fileSize = ftell(file);

		// 파일 위치 초기화
		rewind(file);

		// 파일 사이즈 만큼 버퍼 생성
		char* buffer = new char[fileSize];

		// 파일 값 읽어오기
		size_t readSize = fread(buffer, sizeof(char), fileSize, file);

		// 어서트
		assert(readSize > 0 && "No data is in the stage file.");


		// 파일 값 기반으로 그리기
		// 화면에 액터 그리기

		// 순회를 위한 인덱스 값 설정
		int index = 0;

		// 로직 실행을 위한 위치 값
		// 개행을 만나면 y 값 증가 후 x 값 앞으로 초기화
		Vector2 position;

		while (true)
		{

			// 종료 조건 설정
			// 파일 사이즈 이랑 같거나 작거나 같을 경우 
			if (fileSize <= index)
			{
				// 반복 종료
				break;
			}


			// 현재 문자 값
			char currentChar = buffer[index];

			// 다음 인덱스 값을 위한 증가
			++index;

			// "\n" 만날 경우 y 값 증가, x 0으로 초기화
			// 근데 자료형이 char 니까 "" 가 아닌 ''로 
			if (currentChar == '\n')
			{
				++position.y;
				position.x = 0;
				continue;
			}

			// 현재의 문자 값에 따른 출력
			switch (currentChar)
			{
			case '#':
				SpawnActor<Obstacle>(Obstacle::ObstacleType::Wall, position);
				break;

			case 'I':
				SpawnActor<Tree>(position);
				break;

			case '.':
				SpawnActor<Ground>(position);
				break;

			case '~':
				SpawnActor<Water>(position);
				break;
			
			case '=':
				SpawnActor<Obstacle>(Obstacle::ObstacleType::Bench, position);
				break;

			case 'G':
				SpawnActor<Garbage>(position);
				break;

			case 'U':
				SpawnActor<TrashCan>(position);
				break;


			}

			// 다음 x 값 증가.
			++position.x;
		}

		// 동적 배열 해제 ( 메모리 누수를 방지를 위해 미리 작성 )
		delete[] buffer;
		buffer = nullptr;


		// 파일 닫기 ( 안전을 위해 미리 작성 ) 
		fclose(file);

		// 파일 초기화
		file = nullptr;
	}


