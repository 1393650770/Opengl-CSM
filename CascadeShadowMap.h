#pragma once
#include "Shader.h"
#include "Camera.h"
#include <glm.hpp>
#include "utils.h"
#include <vector>
using namespace std;

class CascadeShadowMap
{
private:
	int CascadeNum;
	vector<vector<glm::vec4>> ClipPointList;
	//���㻮�ֵľ������
	void CalcClipDistance(Camera& camera);
	//��world space�������Ұ�зֵĸ�����
	void GetClipPoint(Camera& camera);
	//����ÿ����Χ�еı任����
	void GetNewLightViewMat4(Camera& camera,glm::vec4 lightPos, glm::vec4 lightDirection);
public:
	
	
	vector<float> CascadeFarPlaneDistantList;
	vector<glm::mat4> LightProViewMat4List;
	int GetCascadeNum() const;
	CascadeShadowMap(int _CascadeNum,Camera& camera);
	virtual~CascadeShadowMap();

	void UpdateCsm(Camera& camera, glm::vec4 lightPos, glm::vec4 lightDirection);
};

