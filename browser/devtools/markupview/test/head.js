/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

const Cu = Components.utils;

let {devtools} = Cu.import("resource://gre/modules/devtools/Loader.jsm", {});
let TargetFactory = devtools.TargetFactory;
let {console} = Cu.import("resource://gre/modules/devtools/Console.jsm", {});

// Clear preferences that may be set during the course of tests.
function clearUserPrefs() {
  Services.prefs.clearUserPref("devtools.inspector.htmlPanelOpen");
  Services.prefs.clearUserPref("devtools.inspector.sidebarOpen");
  Services.prefs.clearUserPref("devtools.inspector.activeSidebar");
}

registerCleanupFunction(clearUserPrefs);

Services.prefs.setBoolPref("devtools.debugger.log", true);
SimpleTest.registerCleanupFunction(() => {
  Services.prefs.clearUserPref("devtools.debugger.log");
});

function getContainerForRawNode(markupView, rawNode) {
  let front = markupView.walker.frontForRawNode(rawNode);
  let container = markupView.getContainer(front);
  return container;
}
