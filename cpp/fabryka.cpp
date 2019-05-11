#include "../hpp/fabryka.hpp"
#include "../hpp/robot.hpp"
#include "../hpp/prostokat.hpp"
#include "../hpp/trojkat.hpp"
#include "../hpp/sciezka.hpp"
Fabryka Fabryka::fabryka;

shared_ptr<ObiektGraficzny> Fabryka::Zbuduj(typObiektu to)
{
switch(to)
{
	case toRobot:
	return make_shared<Robot>();
	break;
		
	case toProstokat:
	return make_shared<Prostokat>();
	break;

	case toTrojkat:
	return make_shared<Trojkat>();
	break;
	
	case toSciezka:
	return make_shared<Sciezka>();
	break;

}

	return make_shared<ObiektGraficzny>();

}

Fabryka& Fabryka::Pobierz()

{

	return fabryka;

}
