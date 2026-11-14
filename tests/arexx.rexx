/* GFOpenPlay's AkikoPlus control-plane acceptance test.
 * GFOpenPlay must already be running. Usage: rx tests/arexx.rexx FILE */
OPTIONS RESULTS
PARSE ARG file
IF file = '' THEN DO
    SAY 'Usage: rx tests/arexx.rexx FILE'
    EXIT 10
END
IF ~SHOW('P', 'GFOPENPLAY.1') THEN DO
    SAY 'GFOPENPLAY.1 is not running'
    EXIT 10
END

ADDRESS 'GFOPENPLAY.1'
'OPEN' file
IF RC ~= 0 THEN EXIT RC
'GETINFO'
IF RC ~= 0 THEN EXIT RC
SAY RESULT
'GETPATH'
IF RC ~= 0 THEN EXIT RC
SAY RESULT
'GETDURATION'
IF RC = 0 THEN SAY 'duration ms:' RESULT
'GETPOSITION'
IF RC = 0 THEN SAY 'position ms:' RESULT
'SEEK 0'
IF RC ~= 0 & RC ~= 5 THEN EXIT RC
'PAUSE'
IF RC ~= 0 THEN EXIT RC
'PLAY'
IF RC ~= 0 THEN EXIT RC
'STOP'
EXIT RC
