<div id="paypal-button-container-P-5PT799148U8831139M22NQTQ"></div>
<script src="https://www.paypal.com/sdk/js?client-id=ARJpggv6QnaXhloyXEkMFhoGvNyPhl8x717ZcXF67dt-p7ayQE6Xg7ksWzkTSl4xK-uKlmnuTUi2xD1K&vault=true&intent=subscription" data-sdk-integration-source="button-factory"></script>
<script>
  paypal.Buttons({
      style: {
          shape: 'pill',
          color: 'gold',
          layout: 'vertical',
          label: 'subscribe'
      },
      createSubscription: function(data, actions) {
        return actions.subscription.create({
          /* Creates the subscription */
          plan_id: 'P-5PT799148U8831139M22NQTQ'
        });
      },
      onApprove: function(data, actions) {
        alert(data.subscriptionID); // You can add optional success message for the subscriber here
      }
  }).render('#paypal-button-container-P-5PT799148U8831139M22NQTQ'); // Renders the PayPal button
</script>