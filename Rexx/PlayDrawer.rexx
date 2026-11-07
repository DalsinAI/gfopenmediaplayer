/* PlayDrawer.rexx: play a drawer's files in GFOpenPlay at the volume given
   (32 when none is) and say what is playing.
   rx PlayDrawer.rexx DRAWER [VOLUME]   (GFOpenPlay running) */
OPTIONS RESULTS
PARSE ARG drawer volume
IF drawer = '' THEN DO
    SAY 'Usage: rx PlayDrawer.rexx DRAWER [VOLUME]'
    EXIT 5
END
IF volume = '' THEN volume = 32
IF ~SHOW('P', 'GFOPENPLAY.1') THEN DO
    SAY 'GFOpenPlay is not running.'
    EXIT 5
END
ADDRESS 'GFOPENPLAY.1'
'OPEN' drawer
IF rc ~= 0 THEN DO
    SAY 'Could not open' drawer '(rc' rc')'
    EXIT rc
END
'VOLUME' volume
'GETFILE'
SAY 'Playing:' RESULT
'STATUS'
SAY 'Status:' RESULT
