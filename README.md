<div dir="rtl" lang="he">
	
# דמויי-מיכלים - שלב א
המטלה נכתבה בהשראת ספריית itertools של פייתון: https://docs.python.org/3/library/itertools.html כדי להראות שאפשר לכתוב ב-++C באותה רמת נוחות שיש בפייתון (עם קצת הכנה מוקדמת).

במטלה זו נלמד לבנות מבנים "דמויי-מיכלים", שאפשר לרוץ עליהם בלולאה למרות שאינם תופסים מקום בזיכרון. השם הרשמי של מבנה מסוג זה הוא iterable. נבנה חמישה דמויי-מיכלים (מהקל אל הקשה):

א. range – מקבל כקלט שני מספרים שלמים, ומייצג את כל המספרים שבין הראשון לאחרון, כולל הראשון ולא כולל האחרון. לדוגמה, range(5,9) מייצג את המספרים 5,6,7,8. ניתן להניח שהפרמטר האחרון גדול או שווה לראשון; אם הפרמטרים שווים אז הטווח ריק.

ב. accumulate - מקבל כקלט מיכל או דמוי-מיכל כלשהו. מחזיר דמוי-מיכל חדש הכולל סכומים חלקיים. לדוגמה, accumulate(range(5,9)) מייצג את המספרים 5, 11, 18, 26 (5, 5+6, 5+6+7, 5+6+7+8). וכך גם accumulate(vector({5,6,7,8})).

ג. accumulate - גירסה נוספת יכולה לקבל פרמטר נוסף שהוא פונקטור בינארי (עם שני ארגומנטים), ולהשתמש בו במקום חיבור. למשל: accumulate(range(5,9), [](int x, int y){return x*y;}) מייצג את המספרים 5, 30, 210, 1680 (5, 5*6, 5*6*7, 5*6*7*8).

ד. filterfalse - מקבל כקלט שני פרמטרים: הראשון הוא פונקטור בוליאני המייצג תנאי, והשני הוא מיכל או דמוי-מיכל. מחזיר דמוי-מיכל חדש, הכולל רק את האיברים בדמוי-המיכל הנתון, שאינם מקיימים את התנאי. לדוגמה: filterfalse([](int i){return i%2==0;}, range(5,9)) מייצג את המספרים האי-זוגיים בטווח הנתון, כלומר: המספרים 5, 7 בלבד.

ה. compress – מקבל כקלט שני מיכלים או דמויי-מיכלים, שחייבים להיות באותו אורך. הראשון כולל עצמים מסוג כלשהו, והשני חייב לכלול עצמים מסוג בוליאני. מחזיר דמוי-מיכל חדש שבו מופיעים איברים מהדמוי-מיכל הראשון, שהאיבר המתאים להם בדמוי-מיכל השני הוא true. לדוגמה, הביטוי compress(range(5,9),vector({true,true,false,true})) מייצג את המספרים 5, 6, 8; compress(string("abcd"),vector({true,true,false,true})) מייצג את האותיות a, b, d.

כדי לראות איך בדיוק המערכת אמורה לעבוד, ראו בקובץ Demo.cpp המצורף.

דגשים:

יש לחזור על החומר של ההרצאות לפני שמתחילים לכתוב, ולהשתמש בו לפי הצורך.
יש לפתור כל סעיף ע"י פונקציה אחת המטפלת בכל סוגי-הנתונים – מספרים, תוים, מחרוזות, וקטורים, וכו' (למשל בסעיף ד, יש לכתוב רק פונקציה filterfalsee אחת – אין לכתוב פונקציות שונות לוקטורים ול-range).
סיבוכיות הזיכרון של כל המבנים צריכה להיות O(1) . למשל, range(1,5) ו range(1,50000) צריכים לתפוס את אותו מקום בזיכרון! אין לשמור 50000 מספרים בערימה.
יש לפתור כל סעיף בקובץ hpp נפרד; שמות הקבצים ע"פ הקובץ Demo.cpp.
דמויי-המיכלים השונים לא תלויים זה בזה, למשל accumulate.hpp לא תלוי ב range.hpp ולהיפך.
יש להקפיד על כללי הנדסת תוכנה, ובפרט: קוד קריא, תיעוד ובדיקות-יחידה מקיפות.
בשלב א עליכם לכתוב את הקבצים הדרושים כך שהפקודות הבאות יעבדו ללא שגיאות קימפול:

make demo && ./demo
make test && ./test
	
	

# איטרטורים - שלב ב


בשלב ב עליכם לכתוב מימוש מלא של המחלקות - 
range, accumulate, filterfalse, compress.

המימוש צריך לעבור את כל הבדיקות - שלכם ושלנו.

אנחנו מריצים את הפקודה הבאה:

<div dir='ltr'>

	make test && ./test

</div>
</div>
