#pragma once
class AActor
{
public:
	AActor();
	AActor(int InX, int InY, char InMesh);
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	void SetActorLocation(int X, int Y);
protected:
	int X;
	int Y;
	char Mesh;
};

