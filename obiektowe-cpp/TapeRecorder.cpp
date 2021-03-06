#include "TapeRecorder.h"
#include <sstream>

TapeRecorder::TapeRecorder()
	: Audio() {
	this->speed = 9.37;
	this->paths = 1;
}

TapeRecorder::TapeRecorder(double power, double f_start, double f_end, double spd, int pths)
	: Audio(power, f_start, f_end)
{
	if (spd < 0) {
		spd = 9.37;
	}
	this->speed = spd;
	if (pths < 0) {
		pths = 1;
	}
	this->paths = pths;
}

Equipment<double>* TapeRecorder::create(std::vector<std::string>)
{
	TapeRecorder* o = new TapeRecorder();
	return o;
}

std::string TapeRecorder::about()
{
	std::stringstream s;
	s << Audio::about();
	s << "Speed: " << this->speed
		<< "\nPaths: " << this->paths << "\n";
	return s.str();
}

void TapeRecorder::importData(std::vector<std::string> v)
{
	if (v.size() >= 2) {
		std::vector<std::string> pv(v.begin() + 2, v.end());
		Audio::importData(pv);
		this->speed = std::stod(v[0]);
		this->paths = std::stoi(v[1]);
	}
}

std::vector<std::string> TapeRecorder::exportData()
{
	std::vector<std::string> pv = Audio::exportData(), v = {
		std::to_string(this->speed),
		std::to_string(this->paths),
	};
	v.insert(v.end(), pv.begin(), pv.end());
	return v;
}

std::vector<std::string> TapeRecorder::getAttribNames()
{
	std::vector<std::string> parentAttribs = Audio::getAttribNames();
	parentAttribs.insert(parentAttribs.begin(), this->attribs.begin(), this->attribs.end());
	return parentAttribs;
}
