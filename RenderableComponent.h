#pragma once

//인터페이스용 클래스 = 추상 클래스
class IRenderableComponent
{
public:
	//순수 가상 함수
	virtual void Render() = 0;
};

