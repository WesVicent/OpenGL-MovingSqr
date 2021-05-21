/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef WINDOW_CONFIG_H
#define WINDOW_CONFIG_H

class WindowConfig {
public:
	static const int WIDTH = 800;
	static const int HEIGHT = 800;
	static const char* TITLE;
};

const char* WindowConfig::TITLE = "WesFerreira OpenGL";

#endif // !WINDOW_CONFIG_H

