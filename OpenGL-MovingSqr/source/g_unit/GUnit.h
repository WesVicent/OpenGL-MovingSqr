/**
	Re-created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef G_UNIT_H
#define G_UNIT_H

namespace G {
	class Unit {
	protected:

	public:
		void virtual allowMovements(MainWindow::EnabledKeys key) = 0;
		void virtual draw() = 0;

		virtual ~Unit() {}; //TODO:

	private:

	};
}

#endif // !G_UNIT_H

