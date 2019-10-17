#ifndef _CUST_BAT_H_
#define _CUST_BAT_H_

//superdragonpt added //TODO
typedef enum
{
	Cust_CC_1600MA = 0x0,
	Cust_CC_1500MA = 0x1,
	Cust_CC_1400MA = 0x2,
	Cust_CC_1300MA = 0x3, //1.08 AMP real value
	Cust_CC_1200MA = 0x4, // 980 MA real value
	Cust_CC_1100MA = 0x5,
	Cust_CC_1000MA = 0x6, // 780 MA real value
	Cust_CC_900MA  = 0x7,
	Cust_CC_800MA  = 0x8, // 600 MA real value
	Cust_CC_700MA  = 0x9,
	Cust_CC_650MA  = 0xA, // 500 MA real value
	Cust_CC_550MA  = 0xB,
	Cust_CC_450MA  = 0xC,
	Cust_CC_400MA  = 0xD,
	Cust_CC_200MA  = 0xE,
	Cust_CC_70MA   = 0xF,
	Cust_CC_0MA	   = 0xDD
}cust_charging_current_enum;
//superdragonpt added, End

typedef struct{	
	unsigned int BattVolt;
	unsigned int BattPercent;
}VBAT_TO_PERCENT;

/* Battery Temperature Protection */
#define MAX_CHARGE_TEMPERATURE  55
#define MIN_CHARGE_TEMPERATURE  2
#define ERR_CHARGE_TEMPERATURE  0xFF

/* Recharging Battery Voltage */
#define RECHARGING_VOLTAGE      4110

/* Charging Current Setting */
#define CONFIG_USB_IF 						0   
#define USB_CHARGER_CURRENT_SUSPEND			Cust_CC_0MA     // def CONFIG_USB_IF
#define USB_CHARGER_CURRENT_UNCONFIGURED	Cust_CC_70MA    // def CONFIG_USB_IF
#define USB_CHARGER_CURRENT_CONFIGURED		Cust_CC_450MA   // def CONFIG_USB_IF
#define USB_CHARGER_CURRENT					Cust_CC_450MA
#define AC_CHARGER_CURRENT					Cust_CC_1300MA
/******************************************************************************
                                  superdragonpt
                             for AC_CHARGER_CURRENT
real measurements:
Cust_CC_1300MA = real 1.08 AMP
Cust_CC_1200MA = real 0.98 AMP / 980 MA
Cust_CC_1000MA = real 0.78 AMP / 780 MA
Cust_CC_800MA  = real 0.60 AMP / 600 MA
Cust_CC_650MA  = real 0.50 AMP / 500 MA

------------------------------------------
Stock kernel: Maximum charge of 1.20 AMP
*******************************************************************************/


/* Battery Meter Solution */
#define CONFIG_ADC_SOLUTION 	1

/* Battery Voltage and Percentage Mapping Table */
VBAT_TO_PERCENT Batt_VoltToPercent_Table[] = {
	/*BattVolt,BattPercent*/
	{3400,0},
	{3691,10},
	{3736,20},
	{3772,30},
	{3797,40},
	{3828,50},
	{3888,60},
	{3944,70},
	{4010,80},
	{4100,90},
	{4176,100},
};

/* Precise Tunning */
#define BATTERY_AVERAGE_SIZE 	30 //12, 15
//12
//15
//30
//60

/* Common setting */
#define R_CURRENT_SENSE 2				// 0.2 Ohm
#define R_BAT_SENSE 4					// times of voltage
#define R_I_SENSE 4						// times of voltage
#define R_CHARGER_1 330
#define R_CHARGER_2 39
#define R_CHARGER_SENSE ((R_CHARGER_1+R_CHARGER_2)/R_CHARGER_2)	// times of voltage
#define V_CHARGER_MAX 6500				// 6 V //superdragonpt decrease to 6v
#define V_CHARGER_MIN 4400				// 4.4 V
#define V_CHARGER_ENABLE 0				// 1:ON , 0:OFF

/* Teperature related setting */
#define RBAT_PULL_UP_R             39000
#define RBAT_PULL_UP_VOLT          1800
#define TBAT_OVER_CRITICAL_LOW     67790
#define BAT_TEMP_PROTECT_ENABLE    1
#define BAT_NTC_10 1
#define BAT_NTC_47 0

/* Battery Notify */
#define BATTERY_NOTIFY_CASE_0001
#define BATTERY_NOTIFY_CASE_0002
//#define BATTERY_NOTIFY_CASE_0003
//#define BATTERY_NOTIFY_CASE_0004
//#define BATTERY_NOTIFY_CASE_0005

//#define CONFIG_POWER_VERIFY

#endif /* _CUST_BAT_H_ */
