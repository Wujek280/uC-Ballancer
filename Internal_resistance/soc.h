
//Funkcji podać napięcie OCV (Open Circuit Voltage ) ogniwa LiIon

int soc(float U)
{ 
 
if(U <3.27){return 0;}
if( U =	3.27	) return (	1	);
if( U <	3.44	) return (	3	);
if( U <	3.61	) return (	5	);
if( U <	3.65	) return (	8	);
if( U <	3.69	) return (	10	);
if( U <	3.70	) return (	13	);
if( U <	3.71	) return (	15	);
if( U <	3.72	) return (	18	);
if( U <	3.73	) return (	20	);
if( U <	3.74	) return (	23	);
if( U <	3.75	) return (	25	);
if( U <	3.76	) return (	28	);
if( U <	3.77	) return (	30	);
if( U <	3.78	) return (	33	);
if( U <	3.79	) return (	35	);
if( U <	3.80	) return (	38	);
if( U <	3.80	) return (	40	);
if( U <	3.81	) return (	43	);
if( U <	3.82	) return (	45	);
if( U <	3.83	) return (	48	);
if( U <	3.84	) return (	50	);
if( U <	3.85	) return (	53	);
if( U <	3.85	) return (	55	);
if( U <	3.86	) return (	58	);
if( U <	3.87	) return (	60	);
if( U <	3.89	) return (	63	);
if( U <	3.91	) return (	65	);
if( U <	3.93	) return (	68	);
if( U <	3.95	) return (	70	);
if( U <	3.97	) return (	73	);
if( U <	3.98	) return (	75	);
if( U <	4.00	) return (	78	);
if( U <	4.02	) return (	80	);
if( U <	4.05	) return (	83	);
if( U <	4.08	) return (	85	);
if( U <	4.10	) return (	88	);
if( U <	4.11	) return (	90	);
if( U <	4.13	) return (	93	);
if( U <	4.15	) return (	95	);
if( U <	4.18 	) return (	98	);
if( U <	4.19 	) return (	99	);
if( U <	4.20 	) return (	100	);

return(0xFF);

}


//OCV Można przeliczyć pod obciążeniem z równania  OCV = SEM +/-  I*R_wewnętrzne(SoC_approx)
