SELECT table1.id, table1.value FROM table1
LEFT JOIN table2 ON (table2.value = table1.value AND table2.id = table1.id)
WHERE table2.value IS NULL
UNION ALL
SELECT table2.id, table2.value FROM table2
LEFT JOIN table1 ON (table1.value = table2.value AND table1.id = table2.id)
WHERE table1.value IS NULL;
