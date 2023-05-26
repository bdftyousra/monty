,>,         Read the first digit into cell 0 and the second digit into cell 1
[           Start a loop
  <-         Decrement the value in cell 0
  >           Move to cell 1
  [           Start another loop
    ->-       Decrement the value in cell 1 and store the result in cell 2
    <+        Increment the value in cell 0 (restoring the original value)
    >-        Decrement the value in cell 1
    >+        Increment the value in cell 2 (restoring the original value)
  ]           End the second loop
  <<          Move back to cell 0
  -           Decrement the value in cell 0
]           End the first loop
<.          Print the result in cell 0
