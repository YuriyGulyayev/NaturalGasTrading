# Natural Gas Trading

A natural gas and petroleum futures trading app. I worked on it intermittently in 2010-2013.

The US Energy Information Administration (EIA) releases the Natural Gas Storage Report and Petroleum Status Report every week at scheduled days and times. 10 milliseconds before the release, the app places entry stop orders to buy above and sell below the market, possibly multiple orders on each side. Then it scrapes the report from the EIA website. As soon as it receives the report, it attempts to cancel the entry orders. In case at least some of the orders got filled before they could be canceled and the resulting position is not empty the app will immediately send an exit market order to close the position.

Multiple instances of the app run on multiple computers and send data to each other. There is no limit on the number of computers.

The app uses the Rithmic R|API for C++.

I was able to make some money with it, but it was tough because my network connections were too slow.

This is a new version that is not fully finished. I didn't include some files.
