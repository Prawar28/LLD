    ll a,b,n;
        cin >> a >> b >> n;

        vector<ll> arr;
        for (int i = 0; i < n; i++) cin >> arr[i];

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(arr[i], a);
        }

        cout << ans << endl;