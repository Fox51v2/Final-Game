var bepns=bepns||function(n,t){function k(){if(r=n("id_rh"),i=n("bepfo"),!i){var u=n("id_d");u&&(i=t("div"),i.id="bepfo",i.className=e,u.parentNode&&u.parentNode.insertBefore(i,u))}g();sj_be(r,h,ut,!1);sj_evt.bind(v,rt);sj_evt.bind("onP1",d,1);sj_evt.bind("id:refreshed",nt,1)}function d(){var n=0,t=setInterval(function(){r&&r.offsetWidth>0&&r.offsetHeight>0?(clearInterval(t),sj_evt.fire("bepready",y)):n==10&&clearInterval(t);n++},200)}function g(){it(r,b)}function nt(){tt(_ge("idd_rwds"),_ge("idd_rwdstrial"))}function tt(n,t){n&&t&&(t.href=n.href,n.h?t.h=n.h:n.getAttribute&&n.getAttribute("h")&&t.setAttribute("h",n.getAttribute("h")))}function it(n,t){n&&(n.href=t)}function rt(n){n[1]!==a&&s()}function o(n,t){if(n&&n.className){var i=" "+n.className+" ";return i.indexOf(" "+t+" ")!==-1}return!1}function c(n,t){n&&!o(n,t)&&(n.className+=" "+t)}function l(n,t){if(o(n,t)){var i=new RegExp("(\\s|^)"+t+"(\\s|$)","g");n.className=n.className.replace(i," ")}}function ut(n){i&&(o(i,e)?et(n):s(n))}function y(n){n&&n>0?ft():p()}function ft(){c(r,"rigleamon")}function p(){l(r,"rigleamon")}function et(n){if(sj_evt.fire("focusChange","bep"),i){i.firstChild||(u=t("iframe"),u.id="bepfm",u.frameBorder="no",u.scrolling="no",u.height=0,sj_be(u,w,ht,!1),i.appendChild(u),f=t("div"),f.id="bepfl",f.innerText=f.textContent="Loading...",i.appendChild(f),st(f));var o=_w.location.search.substr(1),p=/(^|&)rewardstesthooks=1(&|$)/i.exec(o),y=/(?:^|&)rewardsbag=([^&]*)(?:&|$)/i.exec(o);u.src="/rewardsapp/bepflyoutpage?style=modular"+(p&&y?"&atlahostname=localhost&bag="+y[1]:"");l(i,e)}c(r,"openfo");sj_sp(n);sj_be(_d,h,s,!0);sj_evt.fire(v,a)}function s(n){o(i,e)||c(i,e);l(r,"openfo");p();sj_ue(_d,h,s,!0);n&&sj_sp(n)}function ot(n){n&&(n.style.display="none")}function st(n){n&&(n.style.display="block")}function ht(){ot(f);u.height=Math.min(u.contentWindow.document.body.scrollHeight,569)}var a="bepfo",v="onPopTR",r,i,f,u,h="click",w="load",e="b_hide",b="javascript:void(0)";return k(),{sg:y}}(_ge,sj_ce)