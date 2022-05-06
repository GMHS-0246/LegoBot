#include <kipr/wombat.h>

int clawOpen = 454;
int clawClose = 930;

int armUp = 493;
int armFullUp = 493;
int armDown = 1374;
int armMiddle = 1320;
//int armFullDown = 1248;

int rdrive = 990;
int ldrive = 1000;
//1374 lowest, 493 highest
    
int main()
{
    //wait_for_light(0);
    enable_servos(); // turn on servos
    set_servo_position(3, clawClose); // close claw
    msleep(500);
    set_servo_position(2, armFullUp); // arm up
    msleep(500);
    mav(0, -rdrive); // turn right 90 
    mav(1, ldrive);
    msleep(1000); 
    mav(0, rdrive); // drive forwards (out of starting box)
    mav(1, ldrive);
    msleep(5000);
    mav(0, -rdrive); // turn right
    mav(1, ldrive);
    msleep(210); // previously 230
    mav(0, rdrive); // drive forwards
    mav(1, ldrive);
    msleep(7195); // previously 7120
    ao();
    set_servo_position(3, clawOpen); // open claw (place first cube [red] onto airlock)
    msleep(500);
    ao();
    
    // next 15-30 seconds
    mav(0,-rdrive); //go back to not hit cube on airlock
    mav(1,-ldrive);
    msleep(1000);
    mav(0,-rdrive);// turn right 
    mav(1,ldrive);
    msleep(400);
    mav(0, -rdrive); // drive backwards (away from airlock)
    mav(1, -ldrive);
    msleep(1000); // previously 3000
    mav(0,rdrive);// turn left (towards cube rack)
    mav(1,-ldrive);
    msleep(1010); // previously 800
    set_servo_position(2, armMiddle);//lower arm 
    msleep(500);
    mav(0, rdrive);// drive forwards (towards cube rack) [second cube, red]
    mav(1, ldrive);
    msleep(5180);
    ao();
    set_servo_position(3, clawClose);// close claw (pick up second cube [red] for airlock)
    msleep(2000);
    mav(0, -rdrive);// back away from cube rack
    mav(1, -ldrive);
    msleep(3000);
    set_servo_position(2, armFullUp);//arm up
    msleep(500);
    mav(0,-rdrive);
    mav(1, ldrive);
    msleep(1410); // turn to airlock
    mav(0,rdrive);
    mav(1, ldrive);
    msleep(2400); // approach airlock
    ao();
    set_servo_position(3, clawOpen); // open claw (place second cube [red] onto airlock)
    // not fully tested past this point, still in working mode; it's just an outline
    msleep(550);
	
    //30-45 seconds 
    mav(0,-rdrive);
    mav(1, -ldrive);
    msleep(2200);
    mav(0,rdrive);
    mav(1, -ldrive);
    msleep(120);
    set_servo_position(2, armMiddle);//lower arm 
    msleep(500);
    set_servo_position(3, clawOpen); // open claw (place first cube [red] onto airlock)
    msleep(500);
    mav(0,rdrive);
    mav(1, ldrive);
    msleep(4300);
    ao();
    set_servo_position(3, clawClose);// close claw (pick up second cube [red] for airlock)
    msleep(2000);
    mav(0,-rdrive);
    mav(1, -ldrive);
    msleep(3700);
    set_servo_position(2, armFullUp);//arm up
    msleep(500);
    mav(0,-rdrive);
    mav(1, ldrive);
    msleep(1100);
    mav(0,rdrive);
    mav(1, ldrive);
    msleep(1200);
    
    
 
    
    ao();
    return 0;
}

